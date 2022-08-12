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
	void printTransformationResult(bool transformationCorrect);
	void updateMode();
	void handleOption();
	void clearConsole();
	void createBitmapIfPossible();
	void loadHeadersOption();
	void transformateBitmapOption();
	std::string readNameFromInput();

	int option;
	bool programLaunched{true};
	Bitmap source;
	std::string outputName{ "defaultOutput.bmp" }, currentMode{ "Sobel" };
	HeadersOperator* headersOperator;
	Transformator* bitmapTransformator;
	BitmapsSaver bitmapsSaver;
};

