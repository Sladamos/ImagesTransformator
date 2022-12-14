#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "Bmp24Loader.h"
#include "Parser.h"
#include "ModeSelector.h"
#include "FormatSelector.h"
#include "ImagesCreator.h"
using namespace std;

Menu::Menu()
{
	Parser::initialize(source);
	updateFormat();
}

void Menu::updateFormat()
{
	ImagesCreator::updateImage(source, imageFormat);
	currentMode = "Sobel";
	updateMode();
}

void Menu::updateMode()
{
	imagesTransformator = Parser::getTransformator(currentMode);
	headersOperator = Parser::getHeadersOperator(imageFormat);
	imagesSaver = Parser::getImagesSaver(imageFormat);
	contentLoader = Parser::getImagesLoader(imageFormat);
}

void Menu::startProgram()
{
	while (programLaunched)
	{
		printMenu();
		handleOption();
	}
}

void Menu::printMenu()
{
	cout << endl
		<< "1." <<  " Source name: " << source->getName() << "\n"
		<< "2." <<  " Load source" << "\n"
		<< "3." << " Output name: " << outputName << "\n"
		<< "4." << " Current format: " << imageFormat << "\n"
		<< "5." << " Current mode: " << currentMode << "\n"
		<< "6." << " Transform image" << "\n"
		<< "9. Exit\n\n";
}

void Menu::handleOption()
{
	cin >> option;
	clearConsole();
	switch (option)
	{
	case 1:
		source->setName(readNameFromInput());
		break;
	case 2:
		loadSourceOption();
		break;
	case 3:
		outputName = readNameFromInput();
		break;
	case 4:
		changeFormatOption();
		break;
	case 5:
		changeModeOption();
		break;
	case 6:
		transformateImageOption();
		break;
	case 9:
		programLaunched = false;
		break;
	}
}

void Menu::clearConsole()
{
	system("cls");
}

void Menu::loadSourceOption()
{
	source->clear();
	headersOperator->loadHeaders(source);
	loadContentIfPossible();
	cout << source->toString();
}

void Menu::loadContentIfPossible()
{
	if (headersOperator->areHeadersValidate(source))
		contentLoader->loadImageContent(source);
}

string Menu::readNameFromInput()
{
	string name;
	cout << "New name: "; 
	cin.ignore();
	getline(cin, name);
	name += getImageExtension();
	return name;
}

string Menu::getImageExtension()
{
	string imageExtension;
	if (imageFormat == "Bmp24")
		imageExtension = ".bmp";
	return imageExtension;
}

void Menu::changeFormatOption()
{
	string userInput = FormatSelector::selectNewFormat(Parser::getImagesFormats());
	if (userInput != "Undo")
	{
		imageFormat = userInput;
		updateFormat();
	}
	clearConsole();
}

void Menu::changeModeOption()
{
	currentMode = ModeSelector::selectNewMode(currentMode, Parser::getTransformatorsWhichSupport(imageFormat));
	updateMode();
	clearConsole();
}

void Menu::transformateImageOption()
{
	bool transformationCorrect = false;
	if (headersOperator->areHeadersValidate(source) && imagesTransformator != nullptr)
	{
		Image* output = imagesTransformator->transformateImage(outputName, imageFormat);
		imagesSaver->saveImage(output);
		delete output;
		transformationCorrect = true;
	}
	printTransformationResult(transformationCorrect);
}

void Menu::printTransformationResult(bool transformationCorrect)
{
	if(transformationCorrect)
		cout << "Transformation done!\n";
	else
		cout << "Transformation failed!\n";
}

Menu::~Menu()
{
	Parser::clear();
	delete source;
}