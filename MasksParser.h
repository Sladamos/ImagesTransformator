#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Mask.h"
#include "rapidxml.hpp"
class MasksParser
{
public:
	MasksParser();
	std::vector<Mask> loadMasks(const std::string& transformatorName);
private:
	rapidxml::xml_node<>* findMasksNode(const std::string& transformatorName);
	std::vector<Mask> readMasksFromNode(rapidxml::xml_node<>* masksNode);
	Mask readMaskFromNode(rapidxml::xml_node<>* maskNode);
	std::vector<int> parseValuesFrom(const std::string& rowValue);

	const static std::string FILE_PATH;
	const static char DELIMITER;
	std::shared_ptr<rapidxml::xml_document<>> doc;
	std::vector<char> buffer;
	rapidxml::xml_node<>* root_node{ nullptr };
};

