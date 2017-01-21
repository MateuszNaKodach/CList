// CListPWr.cpp : Defines the entry point for the console application.
//


#include "CList.cpp"
#include <iostream>

int main()
{
	CList<int> *clist = new CList<int>{1,2,3};
	//CList<int> *clist = new CList<int>();

	//clist->add(10);
	//clist->add(20);
	std::cout << clist->get(0)<< std::endl;
	std::cout << clist->get(1)<< std::endl;
	try {
		std::cout << clist->get(10);
	}catch(std::out_of_range){
		std::cout << "Oooo, nie ladnie! Wylazles poza zakres listy!"<< std::endl;
	}
	
	system("pause");
    return 0;
}

