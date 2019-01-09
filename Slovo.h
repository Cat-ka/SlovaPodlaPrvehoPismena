#pragma once

#include <string>

class Slovo
{
public:
	Slovo(const char* txt);
	virtual ~Slovo();
	std::string getString() { return text; }

private:
	std::string text;
};

