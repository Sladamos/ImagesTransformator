#pragma once
#include <map>
#include <string>
#include "HeadersOperator.h"
#include "Transformator.h"
class Parser
{
public:
	static HeadersOperator* getHeadersOperator(const std::string& key);
	static Transformator* getTransformator(const std::string& key);
	static void initialize(const Bitmap& source);
	static void clear();
private:
	static void clearHeadersOperators();
	static void clearTransformators();

	static std::map<std::string, Transformator*> transformators;
	static std::map<std::string, HeadersOperator*> headersOperators;
};

