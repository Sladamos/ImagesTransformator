//Author: Slawomir Adamowicz
#include "ConsoleMenu.h"
#include "ProgramEngine.h"
#include "ThreadPool.h"
#include "Bmp24Transformator.h"

int main()
{
	std::vector<Mask> masks;
	auto pig = new Bmp24Transformator(masks);
	auto ganczar = new ThreadPool(4);
	ganczar->queueTask([pig]() {pig->transformateImage(nullptr); });

	std::shared_ptr<Menu> menu = std::shared_ptr<Menu>(new ConsoleMenu());
	ProgramEngine engine(menu);
	engine.startProgram();
	return 0;
}