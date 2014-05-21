#ifndef POINT_H
#define POINT_H
#include "Printable.h"
#include "Shape.h"

class Point : public Shape, public Printable
{
public:
	Point()
	{
		SetPosition(0,0);
	}
	Point (double const& xi, double const& yi)
	{
		SetPosition(xi,yi);
	}
	Point(std::string const& name, double const& xi=0, double const& yi=0):Named(name)
	{
		SetPosition(xi,yi);
	}
	void SetPosition(double xi, double yi)
	{
		m_x = xi;
		m_y = yi;
	}
	Point(Point const& point) : Named(point), Shape(point), Printable(point)
	{
		SetPosition(point.m_x, point.m_y);
	}
	std::string GetPosition() const
	{
		std::string buffer;
		std::stringstream position;
		position << "("<<m_x<<","<<m_y<<")";
		buffer = position.str();
		return buffer;
	}
	double GetX() const
	{
		return m_x;
	}
	double GetY() const
	{
		return m_y;
	}
	double GetDistanceTo(Point const& iotherpoint) const
	{
		double distance;
		distance = sqrt(pow(m_x - iotherpoint.GetX(),2)+pow(m_y - iotherpoint.GetY(),2));
		return distance;
	}
private:
	virtual void ToStream(std::ostream& ostream) const
	{
		ostream <<"Point: "<<GetName().c_str()<<" "<<GetPosition().c_str();
	}
private:
	double m_x;
	double m_y;
};

#endif