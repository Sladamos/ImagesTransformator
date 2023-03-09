#include "MasksParser.h"
#include "Splitter.h"
using namespace std;
using namespace rapidxml;
const std::string MasksParser::FILE_PATH = "Masks.xml";
const char MasksParser::DELIMITER = ';';

MasksParser::MasksParser()
{
	ifstream file(FILE_PATH);
	doc = shared_ptr<xml_document<>>(new xml_document<>);
	buffer = vector<char>((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	(*doc).parse<0>(&buffer[0]);
	root_node = (*doc).first_node("Transformators");
}

std::vector<Mask> MasksParser::loadMasks(const string& transformatorName)
{
	vector<Mask> masks;
	xml_node<>* masksNode = findMasksNode(transformatorName);
	if (masksNode != nullptr)
	{
		masks = readMasksFromNode(masksNode);
	}
	return masks;
}

rapidxml::xml_node<>* MasksParser::findMasksNode(const string& transformatorName)
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

std::vector<Mask> MasksParser::readMasksFromNode(xml_node<>* masksNode)
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

Mask MasksParser::readMaskFromNode(xml_node<>* maskNode)
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

vector<int> MasksParser::parseValuesFrom(const string& rowValue)
{
	vector<int> finalValues;
	Splitter splitter;
	vector<string> values = splitter.split(rowValue, DELIMITER);
	for (string value : values)
	{
		finalValues.push_back(stoi(value));
	}
	return finalValues;
}
