#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "MasksOperator.h"
#include "PixelsLoader.h"
using namespace std;

void Menu::startProgram()
{
	cout << "Welcome to the Sobel converter\n";
	output.setName("defaultOutput.bmp");
	MasksOperator::initializeMasks();
	while (isProgramLaunched)
	{
		printMenu();
		handleOption();
	}
}

void Menu::printMenu()
{
	cout << endl
		<< "1." <<  " Source name: " << source.getName() << "\n"
		<< "2." <<  " Load headers" << "\n"
		<< "3." << " Output name: " << output.getName() << "\n"
		<< "4." << " Transform Bitmap" << "\n"
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
		headersOperator.loadHeaders(source);
		cout << source.getFileHeader() << source.getInfoHeader();
		break;
	case 3:
		output.setName(readNameFromInput());
		break;
	case 4:
		if (headersOperator.areHeadersValidate(source))
		{
			PixelsLoader::createAndLoadPixels(source);
			output.sobelTransformationFrom(source);
			bitmapsSaver.saveBitmap(output);
			cout << "Transformation done!\n";
		}
		break;
	case 9:
		isProgramLaunched = false;
		break;
	}
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

void Menu::clearConsole()
{
	system("cls");
}