#ifndef SHAPE_H
#define SHAPE_H
#include "Named.h"

class Shape : public virtual Named
{
public:
	Shape()
	{
		m_count++;
	}
	Shape(std::string name):Named(name)
	{
		m_count++;
	}
	Shape (const Shape& shape):Named(shape)
	{
		m_count++;
	}
	~Shape()
	{
		m_count--;
	}
	static unsigned int GetCount()
	{
		return m_count;
	}

private:
	static unsigned int m_count;
};

unsigned int Shape::m_count = 0;

#endif