#include "MenuOptionsCreator.h"
#include "ChangeFormatOption.h"
#include "SelectOutputNameOption.h"
#include "ExitOption.h"
#include "LoadSourceOption.h"
#include "Bmp24Loader.h"
#include "Bmp24HeadersOperator.h"
using namespace std;

MenuOptionsCreator::MenuOptionsCreator(std::shared_ptr<Communicator> communicator)
{
	this->communicator = communicator;
}

map<string, map<string, shared_ptr<Option>>> MenuOptionsCreator::createOptions(Menu* menu)
{
	formats = vector<string>{ "Bmp24", "JPG" };
	for (auto format : formats)
	{
		options.insert({ format, map<string, shared_ptr<Option>>() });
	}
	addExitOption(menu);
	addChangeFormatOption(menu);
	addSelectOutputNameOption();
	addBmp24Options(formats[0]);
	return options;
}

const std::vector<std::string>& MenuOptionsCreator::getFormats()
{
	return formats;
}

void MenuOptionsCreator::addBmp24Options(const std::string& format)
{
	string optionName = "LoadSource";
	auto loadSourceOption = shared_ptr<LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>>
		(new LoadSourceOption<Bmp24, Bmp24HeadersOperator, Bmp24Loader>(optionName, communicator));

	auto& namedOptions = options[format];
	auto namedOption = pair<string, shared_ptr<Option>>(optionName, loadSourceOption);

	auto changeFormatOption = std::dynamic_pointer_cast<ChangeFormatOption>(options[formats[0]]["ChangeFormat"]);

	changeFormatOption->formatChanged += [loadSourceOption](auto format) {loadSourceOption->onFormatChanged(); };
	namedOptions.insert(namedOption);
}


void MenuOptionsCreator::addOptionForAllFormats(std::shared_ptr<Option> option)
{
	for (auto& kv : options)
	{
		kv.second.insert({ option->getName(), option });
	}
}

void MenuOptionsCreator::addExitOption(Menu* menu)
{
	string optionName = "Exit";
	shared_ptr<ExitOption> exitOption = shared_ptr<ExitOption>(new ExitOption(optionName));
	exitOption->exitProgram += [menu]() {menu->exitProgram.invoke(); };
	addOptionForAllFormats(exitOption);
}

void MenuOptionsCreator::addChangeFormatOption(Menu* menu)
{
	string optionName = "ChangeFormat";
	shared_ptr<ChangeFormatOption> changeFormatOption = shared_ptr<ChangeFormatOption>(new ChangeFormatOption(optionName, communicator, formats));
	addOptionForAllFormats(changeFormatOption);
	changeFormatOption->formatChanged += [menu](auto format) {menu->onFormatChanged(format); };
	changeFormatOption->formatChanged += [changeFormatOption](auto format) {changeFormatOption->onFormatChanged(format); };
}

void MenuOptionsCreator::addSelectOutputNameOption()
{
	string optionName = "SelectOutputName";
	auto selectOutputNameOption = shared_ptr<SelectOutputNameOption>(new SelectOutputNameOption(optionName, communicator));
	addOptionForAllFormats(selectOutputNameOption);
	auto changeFormatOption = std::dynamic_pointer_cast<ChangeFormatOption>(options[formats[0]]["ChangeFormat"]);
	changeFormatOption->formatChanged += [selectOutputNameOption](auto format) {selectOutputNameOption->onFormatChanged(); };
}
