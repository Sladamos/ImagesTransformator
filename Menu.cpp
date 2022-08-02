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
		<< setw(3) << "1." <<  " Change source name : " + sourceName << "\n"
		<< setw(3) << "2." <<  " Load and validate headers" << "\n"
		<< "10. Exit\n\n\n";
}

void Menu::handleOption()
{
	cin >> option;
	clearConsole();
	switch (option)
	{
	case 1:
		cout << "Source name: ";
		cin >> sourceName;
		break;
	case 2:
		HeadersLoader::loadHeaders(sourceName);
		cout << HeadersLoader::getFileHeader() << HeadersLoader::getInfoHeader();
		break;
	case 10:
		isProgramLaunched = false;
		break;
	}
}

void Menu::clearConsole()
{
	system("cls");
}