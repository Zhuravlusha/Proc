#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include <ctime>

Zhuravleva::Language* Zhuravleva::Language_Input(ifstream &fin)
{
	Language *language = new Language;
	Procedural *proc;
	Object_oriented *oop;
	Functional *func;
	unsigned short int temp;
	fin >> temp;
	fin >> language->year_of_development;
	switch (temp)
	{
	case 1:
		proc = new Procedural;
		language->key = Language::lang::PROCEDURAL;
		proc = (Procedural *)language;
		language = (Language *)Procedural_Input(*proc, fin);
		return language;
	case 2:
		oop = new Object_oriented;
		language->key = Language::lang::OOP;
		oop = (Object_oriented *)language;
		language = (Language *)Object_oriented_Input(*oop, fin);
		return language;
	case 3:
		func = new Functional;
		language->key = Language::lang::FUNCTIONAL;
		func = (Functional *)language;
		language = (Language *)Functional_Input(*func, fin);
		return language;
	default:
		return 0;
	}
}

void Zhuravleva::Language_Output(Language *obj, ofstream &fout)
{
	switch (obj->key)
	{
	case Language::lang::PROCEDURAL:
		Procedural_Output((Procedural*)obj, fout);
		break;
	case Language::lang::OOP:
		Object_oriented_Output((Object_oriented*)obj, fout);
		break;
	case Language::lang::FUNCTIONAL:
		Functional_Output((Functional*)obj, fout);
		break;
	default:
		fout << "Incorrect programming language" << endl;
		return;
	}
	fout << "Year of development = " << obj->year_of_development << endl;
}

bool Zhuravleva::Compare(Language *first, Language *second)
{
	return Past_Years(first) < Past_Years(second);
}

int Zhuravleva::Past_Years(Language *obj)
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - obj->year_of_development;
}