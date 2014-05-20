#ifndef POINT_H
#define POINT_H
#include "Printable.h"
#include "Shape.h"

class Point : public Shape, public Printable
{
public:
	Point()
	{
		m_x = 0;
		m_y = 0;
	}
	Point (int const& xi, int const& yi)
	{
		SetPosition(xi,yi);
	}
	Point(std::string const& name, int const& xi=0, int const& yi=0):Named(name)
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
	void Print() const
	{
		std::cout<<"Point: "<<GetName().c_str()<<" "<<GetPosition().c_str()<<std::endl;
	}
	friend std::ostream & operator << (std::ostream & os, const Point& ipoint)
	{
		os <<"Point: "<<ipoint.GetName().c_str()<<" "<<ipoint.GetPosition().c_str();
		return os;
	}
private:
	double m_x;
	double m_y;
};

#endif