#pragma once
#include <fstream>
#include "Image.h"
template<class T>
class ImagesLoader
{
public:
	void loadImageContent(T* image);
private:
	virtual void prepareAndLoadContent(std::ifstream& imageFile, T* image) = 0;
	const static std::string DIRECTORY_PATH;
};

