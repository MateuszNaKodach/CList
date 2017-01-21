// CListPWr.cpp : Defines the entry point for the console application.
//


#include "CList.h"
#include "CList.cpp"
#include <iostream>

int main()
{
	CList<int> *clist = new CList<int>();

	clist->add(10);
	//std::cout << clist->getNodeValue(0);
	system("pause");
    return 0;
}

