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
	void Print() const
	{
		std::cout<<"Polyline: "<<GetName().c_str()<<" {";
		for (XList<Point>::iterator it = m_plist.begin(); it != m_plist.end(); ++it)
		{
			std::cout<<(*it).GetPosition().c_str();
			if (it.GetNext() != m_plist.end())
				std::cout<<", ";
		}
		
		std::cout<<"}, amount = "<<m_plist.size();
		std::cout<<", lenghth = "<<GetLength()<<std::endl;
	}
	friend std::ostream & operator << (std::ostream & os, const Polyline& ipolyline)
	{
		os<<"Polyline: "<<ipolyline.GetName().c_str()<<" {";
		for (XList<Point>::iterator it = ipolyline.m_plist.begin(); it != ipolyline.m_plist.end(); ++it)
		{
			os<<(*it).GetPosition().c_str();
			if (it.GetNext() != ipolyline.m_plist.end())
				os<<", ";
		}
		
		os<<"}, amount = "<<ipolyline.m_plist.size();
		os<<", lenghth = "<<ipolyline.GetLength();
		return os;
	}
private:
	XList<Point> m_plist;
};
#endif