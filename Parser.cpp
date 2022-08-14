#include <algorithm>
#include "Parser.h"
#include "SobelTransformator.h"
#include "Bmp24HeadersOperator.h"
#include "Bmp24Saver.h"
#include "Bmp24Loader.h"
using namespace std;

map<string, HeadersOperator*> Parser::headersOperators = map<string, HeadersOperator*>();
map<string, ImagesSaver*> Parser::imagesSavers = map<string, ImagesSaver*>();
map<string, ImagesLoader*> Parser::imagesLoaders = map<string, ImagesLoader*>();
map<string, pair<Transformator*, vector<string>>> Parser::transformators = map<string, pair<Transformator*, vector<string>>>();

HeadersOperator* Parser::getHeadersOperator(const string& imageFormat)
{
	auto iter = headersOperators.find(imageFormat);
	if (iter != headersOperators.end())
		return iter->second;
	else
		return nullptr;
}

ImagesSaver* Parser::getImagesSaver(const string& imageFormat)
{
	auto iter = imagesSavers.find(imageFormat);
	if (iter != imagesSavers.end())
		return iter->second;
	else
		return nullptr;
}

ImagesLoader* Parser::getImagesLoader(const string& imageFormat)
{
	auto iter = imagesLoaders.find(imageFormat);
	if (iter != imagesLoaders.end())
		return iter->second;
	else
		return nullptr;
}

Transformator* Parser::getTransformator(const string& mode)
{
	auto iter = transformators.find(mode);
	if (iter != transformators.end())
		return iter->second.first;
	else
		return nullptr;
}

vector<string>& Parser::getSupportedFormats(const std::string& mode)
{
	return transformators.find(mode)->second.second;
}

vector<string> Parser::getImagesFormats()
{
	vector<string> imagesFormats;
	for (auto pairs : headersOperators)
		imagesFormats.push_back(pairs.first);
	return imagesFormats;
}

vector<string> Parser::getTransformatorsWhichSupport(const std::string& imageFormat)
{
	vector<string> transformatorsNames;
	for (auto pairs : transformators)
	{
		vector<string>& supportedFormats = pairs.second.second;
		if (find(supportedFormats.begin(), supportedFormats.end(), imageFormat) != supportedFormats.end())
			transformatorsNames.push_back(pairs.first);
	}
	return transformatorsNames;
}

void Parser::initialize(Bitmap*& source)
{
	initializeTransformators(source);
	initializeBmp24();
}

void Parser::initializeTransformators(Bitmap*& source)
{
	transformators.insert(pair <string, pair <Transformator*, vector<string>>>("Sobel",
		pair <Transformator*, vector<string>>(new SobelTransformator(source), vector<string>())));
}

void Parser::initializeBmp24()
{
	string imageFormat = "Bmp24";
	headersOperators.insert(pair <string, HeadersOperator*>(imageFormat, new Bmp24HeadersOperator()));
	imagesSavers.insert(pair <string, ImagesSaver*>(imageFormat, new Bmp24Saver()));
	imagesLoaders.insert(pair <string, ImagesLoader*>(imageFormat, new Bmp24Loader()));
	addFormat("Sobel", imageFormat);
}

void Parser::addFormat(const string& mode, const string& imageFormat)
{
	getSupportedFormats(mode).push_back(imageFormat);
}

void Parser::clear()
{
	clearHeadersOperators();
	clearTransformators();
	clearSavers();
}

void Parser::clearHeadersOperators()
{
	for (auto headersOperator : headersOperators)
		delete headersOperator.second;
	headersOperators.clear();
}

void Parser::clearTransformators()
{
	for (auto pairs : transformators)
			delete pairs.second.first;
	transformators.clear();
}

void Parser::clearSavers()
{
	for (auto saver : imagesSavers)
		delete saver.second;
	imagesSavers.clear();
}