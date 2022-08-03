#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "HeadersLoader.h"
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
		<< "1." <<  " Source name : " << source.getName() << "\n"
		<< "2." <<  " Load headers" << "\n"
		<< "3." << " Output name : " << output.getName() << "\n"
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
		break;
	case 2:
		HeadersLoader::loadHeaders(source);
		cout << source.getFileHeader() << source.getInfoHeader();
		break;
	case 3:
		output.setName(readNameFromInput());
		break;
	case 4:
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
	cin >> name;
	return name;
}

void Menu::clearConsole()
{
	system("cls");
}