#pragma once
#include "BitmapHeadersOperator.h"
#include "Bmp24.h"
class Bmp24HeadersOperator : public BitmapHeadersOperator<Bmp24, Bmp24Header>
{
public:
	Bmp24HeadersOperator(const std::string& directory_path);
	bool areHeadersValidate(std::shared_ptr<Bmp24> bitmap) override;
private:
	virtual void loadDIBHeader(std::ifstream& bitmapFile, std::shared_ptr<Bmp24Header> bitmapHeader) override;
	virtual Bmp24HeaderPtr createHeaderPtr() override;
};

