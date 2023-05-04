#include "RapidXMLMasksParser.h"
#include "StringsOperator.h"
using namespace std;
using namespace rapidxml;
const std::string RapidXMLMasksParser::FILE_PATH = "Masks.xml";
const char RapidXMLMasksParser::DELIMITER = ';';

RapidXMLMasksParser::RapidXMLMasksParser() : MasksParser()
{
	ifstream file(FILE_PATH);
	doc = shared_ptr<xml_document<>>(new xml_document<>);
	buffer = vector<char>((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	(*doc).parse<0>(&buffer[0]);
	root_node = (*doc).first_node("Transformators");
}

std::vector<Mask> RapidXMLMasksParser::loadMasks(const string& transformatorName)
{
	vector<Mask> masks;
	xml_node<>* masksNode = findMasksNode(transformatorName);
	if (masksNode != nullptr)
	{
		masks = readMasksFromNode(masksNode);
	}
	return masks;
}

rapidxml::xml_node<>* RapidXMLMasksParser::findMasksNode(const string& transformatorName)
{
	for (xml_node<>* transformatorNode = root_node->first_node("Transformator");
		transformatorNode; transformatorNode = transformatorNode->next_sibling())
	{
		string name = transformatorNode->first_attribute("name")->value();
		if (name == transformatorName)
			return transformatorNode->first_node("Masks");
	}
	return nullptr;
}

std::vector<Mask> RapidXMLMasksParser::readMasksFromNode(xml_node<>* masksNode)
{
	vector<Mask> masks;
	for (xml_node<>* maskNode = masksNode->first_node("Mask");
		maskNode; maskNode = maskNode->next_sibling())
	{
		Mask mask = readMaskFromNode(maskNode);
		masks.push_back(mask);
	}
	return masks;
}

Mask RapidXMLMasksParser::readMaskFromNode(xml_node<>* maskNode)
{
	vector<int> maskValues;
	int size = 0;
	for (xml_node<>* rowNode = maskNode->first_node("Row");
		rowNode; rowNode = rowNode->next_sibling())
	{
		size++;
		string rowValue = rowNode->value();
		vector<int> parsedValues = parseValuesFrom(rowValue);
		maskValues.insert(maskValues.end(), parsedValues.begin(), parsedValues.end());
	}
	return Mask(size, maskValues);
}

vector<int> RapidXMLMasksParser::parseValuesFrom(const string& rowValue)
{
	vector<int> finalValues;
	StringsOperator splitter;
	vector<string> values = splitter.split(rowValue, DELIMITER);
	for (string value : values)
	{
		finalValues.push_back(stoi(value));
	}
	return finalValues;
}
