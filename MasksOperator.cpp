#include "MasksOperator.h"

MasksOperator::MasksOperator(const std::string& masksPath) : masksPath(masksPath)
{
}

std::vector<Mask> MasksOperator::getMasks()
{
	std::shared_ptr<MasksParser> parser = std::shared_ptr<RapidXMLMasksParser>(new RapidXMLMasksParser(masksPath));
	std::vector<Mask> masks = parser->loadMasks(getName());
	return masks;
}
