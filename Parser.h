#pragma once
#include <map>
#include <string>
#include "HeadersOperator.h"
#include "Transformator.h"
class Parser
{
public:
	static HeadersOperator* getHeadersOperator(const std::string& imageType);
	static Transformator* getTransformator(const std::string& imageType, const std::string& currentMode);
	static std::map<std::string, Transformator*>& getTransformators(const std::string& imageType);
	static void initialize(const Bitmap& source);
	static void clear();
private:
	static void initializeBmp24(const Bitmap& source);
	static void createMap(const std::string& imageType);
	static void clearHeadersOperators();
	static void clearTransformators();

	static std::map<std::string, std::map<std::string, Transformator*>> transformators;
	static std::map<std::string, HeadersOperator*> headersOperators;
};

