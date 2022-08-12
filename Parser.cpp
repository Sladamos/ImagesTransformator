#include "Parser.h"
#include "SobelTransformator.h"
#include "SobelHeadersOperator.h"
using namespace std;

map<string, HeadersOperator*> Parser::headersOperators = map<string, HeadersOperator*>();
map<string, Transformator*> Parser::transformators = map<string, Transformator*>();

HeadersOperator* Parser::getHeadersOperator(const string& key)
{
	return (headersOperators.find(key)->second);
}

Transformator* Parser::getTransformator(const string& key)
{
	return (transformators.find(key)->second);
}

void Parser::initialize(const Bitmap& source)
{
	transformators.insert(pair <string, Transformator*>("Sobel", new SobelTransformator(source)));
	headersOperators.insert(pair <string, HeadersOperator*>("Sobel", new SobelHeadersOperator()));
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
	headersOperators.clear();
}

void Parser::clearTransformators()
{
	for (auto transformator : transformators)
		delete transformator.second;
	transformators.clear();
}