#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Zhuravleva
{
	struct Node
	{
		Language *language;
		Node *Next;//óêàçàòåëü íà ñëåäóþùèé ýëåìåíò â ñïèñêå
		Node *Prev;//óêàçàòåëü íà ïðåäûäóùèé ýëåìåíò â ñïèñêå
	};

	struct LinkedList
	{
		Node *First;//óêàçàòåëü íà ïåðâûé ýëåìåíò â ñâÿçíîì ñïèñêå
		Node *Last;//óêàçàòåëü íà ïîñëåäíèé ýëåìåíò â ñâÿçíîì ñïèñêå
		size_t SizeList;
	};

	void Init(LinkedList &obj);
	void Clear(LinkedList &obj);

	void LinkedList_Input(LinkedList &obj, ifstream &fin);
	void LinkedList_Output(LinkedList &obj, ofstream &fout);

	void Only_Procedural(LinkedList &obj, ofstream &fout);
}

#endif // !LINKEDLIST_H