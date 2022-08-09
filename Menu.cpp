#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "MasksOperator.h"
#include "PixelsLoader.h"
using namespace std;

void Menu::startProgram()
{
	cout << "Welcome to the Sobel converter\n";
	while (isProgramLaunched)
	{
		printMenu();
		handleOption();
	}
}

void Menu::printMenu()
{
	cout << endl
		<< "1." <<  " Source name: " << source << "\n"
		<< "2." <<  " Load headers for Sobel" << "\n"
		<< "3." << " Output name: " << outputName << "\n"
		<< "4." << " Transform Bitmap by Sobel" << "\n"
		<< "9. Exit\n\n\n";
}

void Menu::handleOption()
{
	cin >> option;
	clearConsole();
	switch (option)
	{
	case 1:
		source.setName(readNameFromInput());
		source.resetHeaders();
		break;
	case 2:
		loadHeadersOption();
		break;
	case 3:
		outputName = readNameFromInput();
		break;
	case 4:
		transformateBitmapOption();
		break;
	case 9:
		isProgramLaunched = false;
		break;
	}
}

void Menu::clearConsole()
{
	system("cls");
}

void Menu::loadHeadersOption()
{
	clearCurrentLoadedThings();
	headersOperator = new SobelHeadersOperator();
	headersOperator->loadHeaders(source);
	createBitmapAndTransformatorIfPossible();
	printHeaders();
}

void Menu::clearCurrentLoadedThings()
{
	if (headersOperator != nullptr)
		delete headersOperator;
	headersOperator = nullptr;

	if (bitmapTransformator != nullptr)
		delete bitmapTransformator;
	bitmapTransformator = nullptr;

	source.clearPixelsIfNecessary();
}

void Menu::createBitmapAndTransformatorIfPossible()
{
	if (headersOperator->areHeadersValidate(source))
	{
		PixelsLoader::createAndLoadPixels(source);
		bitmapTransformator = new SobelTransformator(source);
	}
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
	if (headersOperator != nullptr && headersOperator->areHeadersValidate(source))
	{
		Bitmap* output = bitmapTransformator->transformateBitmap(outputName);
		bitmapsSaver.saveBitmap(*output);
		delete output;
		cout << "Transformation done!\n";
	}
	else
		cout << "Transformation failed!\n";
}

Menu::~Menu()
{
	clearCurrentLoadedThings();
}