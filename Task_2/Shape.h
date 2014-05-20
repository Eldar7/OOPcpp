#ifndef SHAPE_H
#define SHAPE_H
#include "Named.h"

class Shape : public virtual Named
{
public:
	Shape()
	{
		sm_count++;
	}
	Shape(std::string name):Named(name)
	{
		sm_count++;
	}
	Shape (const Shape& shape):Named(shape)
	{
		sm_count++;
	}
	virtual ~Shape()
	{
		sm_count--;
	}
	static unsigned int GetCount()
	{
		return sm_count;
	}

private:
	static unsigned int sm_count;
};

unsigned int Shape::sm_count = 0;

#endif