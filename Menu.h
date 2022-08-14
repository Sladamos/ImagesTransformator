#pragma once
#include "ImagesSaver.h"
#include "HeadersOperator.h"
#include "ImagesLoader.h"
#include "Transformator.h"
class Menu
{
public:
	Menu();
	~Menu();
	void startProgram();
private:
	void printMenu();
	void printTransformationResult(bool transformationCorrect);
	void updateMode();
	void updateFormat();
	void handleOption();
	void clearConsole();
	void loadContentIfPossible();
	void loadSourceOption();
	void changeFormatOption();
	void changeModeOption();
	void transformateImageOption();
	std::string readNameFromInput();
	std::string getImageExtension();

	int option;
	bool programLaunched{true};
	Image* source{nullptr};
	std::string outputName{ "defaultOutput.bmp" }, currentMode{ "Sobel" }, imageFormat{ "Bmp24" };
	HeadersOperator* headersOperator;
	Transformator* imagesTransformator;
	ImagesSaver* imagesSaver;
	ImagesLoader* contentLoader;
};

