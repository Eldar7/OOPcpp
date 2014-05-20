#ifndef SQUARE_H
#define SQUARE_H
#include "Rect.h"
#include "Square.h"

class isnotsquare: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Side of the square is not equal";
	}
} isnotsq;


class Square : public Rect
{
public:
	Square(Point const& ileftdown, Point const& irightup):Rect(ileftdown,irightup)
	{
		if ((rightup.GetX() - leftdown.GetX())!=(rightup.GetY() - leftdown.GetY()))
			throw isnotsq;
	}
	Square(std::string const& name, Point const& ileftdown, Point const& irightup):Rect(ileftdown,irightup), Named(name)
	{
		if ((rightup.GetX() - leftdown.GetX())!=(rightup.GetY() - leftdown.GetY()))
			throw isnotsq;
	}
	void GetInfo(std::ostream& ostream) const
	{
		ostream <<"Square: "<<GetName().c_str()<<" {"<<Getleftdown().GetPosition().c_str();
		ostream <<", "<<Getrightup().GetPosition().c_str()<<"}, area = "<<GetArea();
	}
};

#endif