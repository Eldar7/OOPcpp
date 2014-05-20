#ifndef RECT_H
#define RECT_H
#include "Shape.h"
#include "Printable.h"
#include "Rect.h"

class Rect : public Shape, public Printable
{
public:
	Rect(Point const& ileftdown, Point const& irightup)
	{
		leftdown = ileftdown;
		rightup = irightup;
	}
	Rect(std::string const& name, Point const& ileftdown, Point const& irightup) : Named(name)
	{
		leftdown = ileftdown;
		rightup = irightup;
	}
	double GetArea() const
	{
		double area = 0;
		area = (rightup.GetX() - leftdown.GetX())*(rightup.GetY() - leftdown.GetY());
		if (area >=0)
			return area;
		else
			return -area;
	}
	Point Getleftdown() const
	{
		return leftdown;
	}
	Point Getrightup() const
	{
		return rightup;
	}
	virtual void Print()
	{
		std::cout<<"Rectangle: "<<GetName().c_str()<<" {"<<leftdown.GetPosition().c_str()<<", "<<rightup.GetPosition().c_str()<<"}, area = "<<GetArea()<<std::endl;
	}
	friend std::ostream & operator << (std::ostream & os, const Rect& irect)
	{
		os <<"Rectangle: "<<irect.GetName().c_str()<<" {"<<irect.Getleftdown().GetPosition().c_str();
		os <<", "<<irect.Getrightup().GetPosition().c_str()<<"}, area = "<<irect.GetArea();
		return os;
	}
protected:
	Point leftdown;
	Point rightup;
};

#endif