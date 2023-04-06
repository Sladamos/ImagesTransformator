#include <iostream>
#include <iomanip>
#include "Menuz.h"
#include "Bmp24Loader.h"
#include "Parser.h"
#include "ModeSelector.h"
#include "FormatSelector.h"
#include "ImagesCreator.h"
using namespace std;

Menuz::Menuz()
{
	Parser::initialize(source);
	updateFormat();
}

void Menuz::updateFormat()
{
	ImagesCreator::updateImage(source, imageFormat);
	currentMode = "Sobel";
	updateMode();
}

void Menuz::updateMode()
{
	imagesTransformator = Parser::getTransformator(currentMode);
	headersOperator = Parser::getHeadersOperator(imageFormat);
	imagesSaver = Parser::getImagesSaver(imageFormat);
	contentLoader = Parser::getImagesLoader(imageFormat);
}

void Menuz::startProgram()
{
	while (programLaunched)
	{
		printMenuz();
		handleOption();
	}
}

void Menuz::handleOption()
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

void Menuz::clearConsole()
{
	system("cls");
}

void Menuz::loadSourceOption()
{
	source->clear();
	headersOperator->loadHeaders(source);
	loadContentIfPossible();
	cout << source->toString();
}

void Menuz::loadContentIfPossible()
{
	if (headersOperator->areHeadersValidate(source))
		contentLoader->loadImageContent(source);
}

string Menuz::readNameFromInput()
{
	string name;
	cout << "New name: "; 
	cin.ignore();
	getline(cin, name);
	name += getImageExtension();
	return name;
}

string Menuz::getImageExtension()
{
	string imageExtension;
	if (imageFormat == "Bmp24")
		imageExtension = ".bmp";
	return imageExtension;
}

void Menuz::changeFormatOption()
{
	string userInput = FormatSelector::selectNewFormat(Parser::getImagesFormats());
	if (userInput != "Undo")
	{
		imageFormat = userInput;
		updateFormat();
	}
	clearConsole();
}

void Menuz::changeModeOption()
{
	currentMode = ModeSelector::selectNewMode(currentMode, Parser::getTransformatorsWhichSupport(imageFormat));
	updateMode();
	clearConsole();
}

void Menuz::transformateImageOption()
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

void Menuz::printTransformationResult(bool transformationCorrect)
{
	if(transformationCorrect)
		cout << "Transformation done!\n";
	else
		cout << "Transformation failed!\n";
}

Menuz::~Menuz()
{
	Parser::clear();
	delete source;
}