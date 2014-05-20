#ifndef NAMED_H
#define NAMED_H
#include <iostream>
#include <sstream>
#include <exception>
#include <math.h>

class Named
{
public:
	Named()
	{
		m_name = "noname";
	}
	Named(std::string const& name)
	{
		m_name = name;
	}
	std::string GetName() const
	{
		return m_name;
	}
	void Rename(std::string const& new_name)
	{
		m_name = new_name;
	}
	friend std::ostream & operator << (std::ostream & os, const Named& inamed)
	{
		os << inamed.GetName();
		return os;
	}
private:
	std::string m_name;
};

#endif