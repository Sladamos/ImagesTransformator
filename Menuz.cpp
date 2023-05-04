/*#include <iostream>
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
			changeModeOption();	easy: changeFilter , onFilterChanged with Masks vector
			:> options creator class with menu instance in method
			createOptions(T )


		break;
	}
}

void Menuz::changeModeOption()
{
	currentMode = ModeSelector::selectNewMode(currentMode, Parser::getTransformatorsWhichSupport(imageFormat));
	updateMode();
	clearConsole();
} */