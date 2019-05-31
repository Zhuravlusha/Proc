#include "Procedural.h"

Zhuravleva::Procedural * Zhuravleva::Procedural_Input(Procedural &obj, ifstream &fin)
{
	fin >> obj.abstract_type;
	return &obj;
}

void Zhuravleva::Procedural_Output(Procedural *obj, ofstream &fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (obj->abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
}