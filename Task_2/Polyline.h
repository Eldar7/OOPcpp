#ifndef POLYLINE_H
#define POLYLINE_H
#include "Shape.h"
#include "Printable.h"
#include "Polyline.h"
#include "../Task_1/XList.h"

class Polyline : public Shape, public Printable
{
public:
	Polyline()
	{
	}
	Polyline(std::string const& name):Named(name)
	{
	}
	void AddPoint (Point const& ipoint)
	{
		m_plist.push_back(ipoint);
	}
	double GetLength() const
	{
		double length = 0;
		for (XList<Point>::iterator it = m_plist.begin(); it != m_plist.end(); ++it)
		{
			if (it.GetNext() != m_plist.end())
			{
				length+=(*it).GetDistanceTo(*(it.GetNext()));
			}
		}
		return length;
	}
	void GetInfo(std::ostream& ostream) const
	{
		ostream<<"Polyline: "<<GetName().c_str()<<" {";
		for (XList<Point>::iterator it = m_plist.begin(); it != m_plist.end(); ++it)
		{
			ostream<<(*it).GetPosition().c_str();
			if (it.GetNext() != m_plist.end())
				ostream<<", ";
		}
		ostream<<"}, amount = "<<m_plist.size();
		ostream<<", lenghth = "<<GetLength();
	}
private:
	XList<Point> m_plist;
};
#endif