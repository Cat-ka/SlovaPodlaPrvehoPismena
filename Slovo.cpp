#include "Slovo.h"
#include <string>

Slovo::Slovo(const char * txt)
{
	text = txt;

	if (text.length() > 50)
	{
		text.erase(text.begin() + 50, text.begin() + text.length());
	}
}

Slovo::~Slovo()
{
}
