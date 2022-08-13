#include "Parser.h"
#include "SobelTransformator.h"
#include "Bmp24HeadersOperator.h"
using namespace std;

map<string, HeadersOperator*> Parser::headersOperators = map<string, HeadersOperator*>();
map<string, map<string, Transformator*>> Parser::transformators = map<string, map<string, Transformator*>>();

HeadersOperator* Parser::getHeadersOperator(const string& imageType)
{
	auto iter = headersOperators.find(imageType);
	if (iter != headersOperators.end())
		return iter->second;
	else
		return nullptr;
}

Transformator* Parser::getTransformator(const string& imageType, const string& currentMode)
{
	auto& imageTransformators = getTransformators(imageType);
	auto iter = imageTransformators.find(currentMode);
	if (iter != imageTransformators.end())
		return iter->second;
	else
		return nullptr;
}

map<string, Transformator*>& Parser::getTransformators(const string& imageType)
{
	return transformators.find(imageType)->second;
}

void Parser::initialize(const Bitmap& source)
{
	initializeBmp24(source);
}

void Parser::initializeBmp24(const Bitmap& source)
{
	string imageType = "Bmp24";
	createMap(imageType);
	auto& imageTransformators = getTransformators(imageType);
	headersOperators.insert(pair <string, HeadersOperator*>(imageType, new Bmp24HeadersOperator()));
	imageTransformators.insert(pair <string, Transformator*>("Sobel", new SobelTransformator(source)));
}

void Parser::createMap(const string& imageType)
{
	transformators.insert(pair <string, map<string, Transformator*>>(imageType, map<string, Transformator*>()));
}

void Parser::clear()
{
	clearHeadersOperators();
	clearTransformators();
}

void Parser::clearHeadersOperators()
{
	for (auto headersOperator : headersOperators)
		delete headersOperator.second;
}

void Parser::clearTransformators()
{
	for (auto pairs : transformators)
		for (auto transformator : pairs.second)
			delete transformator.second;
}