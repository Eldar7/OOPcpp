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
private:
	virtual void ToStream(std::ostream& ostream) const
	{
		ostream <<"Rectangle: "<<GetName().c_str()<<" {"<<Getleftdown().GetPosition().c_str();
		ostream <<", "<<Getrightup().GetPosition().c_str()<<"}, area = "<<GetArea();
	}
protected:
	Point leftdown;
	Point rightup;
};

#endif