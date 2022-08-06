#pragma once
#include <vector>
class MasksOperator
{
public:
	constexpr static int numberOfMasks = 4;
	constexpr static int maskSize = 3;
	static std::vector<int> getMask(int maskNumber);
	static void initializeMasks();
private:
	static std::vector<std::vector<int>> masks;
};

