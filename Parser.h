#pragma once
#include <map>
#include <vector>
#include <string>
#include "HeadersOperator.h"
#include "Transformator.h"
#include "ImagesSaver.h"
#include "ImagesLoader.h"/*
class Parser
{
public:
	static HeadersOperator* getHeadersOperator(const std::string& imageFormat);
	static ImagesSaver* getImagesSaver(const std::string& imageFormat);
	static ImagesLoader* getImagesLoader(const std::string& imageFormat);
	static Transformator* getTransformator(const std::string& mode);
	static std::vector<std::string>& getSupportedFormats(const std::string& mode);
	static std::vector<std::string> getImagesFormats();
	static std::vector<std::string> getTransformatorsWhichSupport(const std::string& imageFormat);
	static void initialize(Image*& source);
	static void clear();
private:
	static void initializeTransformators(Image*& source);
	static void initializeBmp24();
	static void addFormat(const std::string& mode, const std::string& imageFormat);
	static void clearHeadersOperators();
	static void clearTransformators();
	static void clearSavers();
	static void clearLoaders();

	static std::map<std::string, std::pair<Transformator*, std::vector<std::string>>> transformators;
	static std::map<std::string, HeadersOperator*> headersOperators;
	static std::map<std::string, ImagesSaver*> imagesSavers;
	static std::map<std::string, ImagesLoader*> imagesLoaders;
};

*/