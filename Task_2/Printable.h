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
	virtual void GetInfo(std::ostream&) const = 0;
	friend std::ostream & operator << (std::ostream & os, const Printable& printable)
	{
		printable.GetInfo(os);
		return os;
	}
	void Print() const
	{
		std::cout<<*this<<std::endl;
	}
};

#endif