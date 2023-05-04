#include "MasksOperator.h"

std::vector<Mask> MasksOperator::getMasks()
{
	std::shared_ptr<MasksParser> parser = std::shared_ptr<RapidXMLMasksParser>(new RapidXMLMasksParser());
	std::vector<Mask> masks = parser->loadMasks(getName());
	return masks;
}
