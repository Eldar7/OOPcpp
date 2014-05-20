#ifndef PRINTABLE_H
#define PRINTABLE_H
#include "Named.h"

class Printable : public virtual Named
{
public:
	Printable()
	{
	}
	Printable(std::string name):Named(name)
	{
	}
	void Print() const
	{
		std::cout<<*this<<std::endl;
	}
};

#endif