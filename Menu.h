#pragma once
#include "Bitmap.h"
#include "SobelHeadersOperator.h"
#include "SobelTransformator.h"
#include "BitmapsSaver.h"
class Menu
{
public:
	~Menu();
	void startProgram();
private:
	void printMenu();
	void printHeaders();
	void handleOption();
	void clearConsole();
	void clearCurrentLoadedThings();
	void createBitmapAndTransformatorIfPossible();
	void loadHeadersOption();
	void transformateBitmapOption();
	std::string readNameFromInput();

	int option;
	bool isProgramLaunched{1};
	Bitmap source;
	std::string outputName{ "defaultOutput.bmp" };
	HeadersOperator* headersOperator{nullptr};
	Transformator* bitmapTransformator{nullptr};
	BitmapsSaver bitmapsSaver;
};

