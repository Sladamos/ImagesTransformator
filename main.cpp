#include <iostream>
#include <string>
#include "Bitmaps24BitLoader.h"
using namespace std;

int main()
{
	string name;
	cin >> name;
	BitmapsLoader* loader = new Bitmaps24BitLoader;
	loader->loadBmp(name);
	delete loader;
	return 0;
}