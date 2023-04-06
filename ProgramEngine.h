#pragma once
class ProgramEngine
{
public:
	ProgramEngine();
	void startProgram();
private:
	bool isProgramLaunched;
	std::shared_ptr<Menu> menu;
};

