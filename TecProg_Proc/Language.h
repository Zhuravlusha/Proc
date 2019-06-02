#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"

namespace Zhuravleva
{
	struct Language
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
	};

	Language* Language_Input(ifstream &fin);
	void Language_Output(Language *obj, ofstream &fout);
	int Past_Years(Language *obj);
	bool Compare(Language *first, Language *second);
}

#endif // !LANGUAGE_H