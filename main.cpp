#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>
#include "Slovo.h"

int main(int argc, char* argv[])
{
	//vytvorenie zoznamov
	std::vector<Slovo*>* zoznam = new std::vector<Slovo*>[128];

	//citanie zo suboru
	std::ifstream inputFile("input.txt");

	if (inputFile.is_open())
	{
		std::string word;
		while (inputFile >> word)
		{
			char pismeno = word.data()[0];
			zoznam[pismeno].push_back(new Slovo(word.data()));
		}
		inputFile.close();
	}
	else
	{
		printf("Subor 'input.txt' z ktoreho sa chystame citat neexistuje. Neboli nacitane ziadne slova!\n");
	}

	//zapisanie do suboru
	FILE* outputFile = fopen("output.txt", "w");

	for (int i = 0; i < 128; ++i)
	{
		if (zoznam[i].size() > 0)
		{
			fprintf(outputFile, "%c: %d\n", i, zoznam[i].size());
		}
	}
	fclose(outputFile);

	//citanie z klavesnice
	while (true)
	{
		printf("Zadaj zaciatocne pismeno: ");

		std::string input;
		std::cin >> input;
		char pismeno = input.data()[0];

		if (zoznam[pismeno].size() == 0)
		{
			printf("Zoznam s pismenom '%c' je prazdny!\n", pismeno);
		}
		else
		{
			printf("Slova v zozname '%c' (celkovo: %d): ", pismeno, zoznam[pismeno].size());

			for (Slovo* s : zoznam[pismeno])
			{
				printf("%s ", s->getString().data());
			}

			printf("\n");
		}
	}

	//vymazanie pamate
	for (int i = 0; i < 128; ++i)
	{
		for (Slovo* s : zoznam[i])
		{
			delete s;
		}
	}
	delete[] zoznam;
	return 0;
}