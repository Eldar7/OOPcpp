#include <iostream>
#include "XList.h"

int main()
{
	XList<int> list;
	XList<int>::iterator it;
	XList<int>::reverse_iterator rit;
	
	list.push_back(11);
	list.push_front(8);
	list.push_back(12);
	list.push_back(13);
	list.push_back(14);

	list.print();
	std::cout<<list.size()<<std::endl;
	//list.clear();

	it = list.begin();
	std::cout<<*(++it)<<std::endl;

	for (it = list.begin(); it != list.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;

	for (rit = list.rbegin(); rit != list.rend(); ++rit)
		std::cout<<*rit<<" ";
	std::cout<<std::endl;

	it = list.end();

	return 0;
}