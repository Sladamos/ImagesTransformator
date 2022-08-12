#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "PixelsLoader.h"
#include "Parser.h"
#include "ModeSelector.h"
using namespace std;

void Menu::startProgram()
{
	Parser::initialize(source);
	updateMode();
	while (programLaunched)
	{
		printMenu();
		handleOption();
	}
}

void Menu::updateMode()
{
	bitmapTransformator = Parser::getTransformator(currentMode);
	headersOperator = Parser::getHeadersOperator(currentMode);
}

void Menu::printMenu()
{
	cout << endl
		<< "1." <<  " Source name: " << source << "\n"
		<< "2." <<  " Load source" << "\n"
		<< "3." << " Output name: " << outputName << "\n"
		<< "4." << " Current mode: " << currentMode << "\n"
		<< "5." << " Transform bitmap" << "\n"
		<< "9. Exit\n\n";
}

void Menu::handleOption()
{
	cin >> option;
	clearConsole();
	switch (option)
	{
	case 1:
		source.setName(readNameFromInput());
		break;
	case 2:
		loadHeadersOption();
		break;
	case 3:
		outputName = readNameFromInput();
		break;
	case 4:
		currentMode = ModeSelector::selectNewMode(currentMode);
		clearConsole();
		break;
	case 5:
		transformateBitmapOption();
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

void Menu::loadHeadersOption()
{
	source.clearPixelsIfNecessary();
	headersOperator->loadHeaders(source);
	createBitmapIfPossible();
	printHeaders();
}

void Menu::createBitmapIfPossible()
{
	if (headersOperator->areHeadersValidate(source))
		PixelsLoader::createAndLoadPixels(source);
}

void Menu::printHeaders()
{
	cout << source.getFileHeader() << source.getInfoHeader();
}

string Menu::readNameFromInput()
{
	string name;
	cout << "New name: "; 
	cin.ignore();
	getline(cin, name);
	name += ".bmp";
	return name;
}

void Menu::transformateBitmapOption()
{
	bool transformationCorrect = false;
	if (headersOperator->areHeadersValidate(source))
	{
		Bitmap* output = bitmapTransformator->transformateBitmap(outputName);
		bitmapsSaver.saveBitmap(*output);
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
}