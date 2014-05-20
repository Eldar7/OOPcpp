#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Printable.h"
#include "Circle.h"

class Circle : public Shape, public Printable
{
public:
	Circle (Point const& icenter, int const& iradius=0)
	{
		m_center = icenter;
		m_radius = iradius;
	}
	Circle (std::string const& name, Point const& icenter, int const& iradius=0) : Named(name)
	{
		m_center = icenter;
		m_radius = iradius;
	}
	double GetArea() const
	{
		return 3.14*m_radius*m_radius;
	}
	Point GetCenter() const
	{
		return m_center;
	}
	double GetRadius() const
	{
		return m_radius;
	}
	void Print() const
	{
		std::cout<<"Circle: "<<GetName().c_str()<<" {"<<m_center.GetPosition().c_str()<<", "<<m_radius<<"}, area = "<<GetArea()<<std::endl;
	}
	friend std::ostream & operator << (std::ostream & os, const Circle& icircle)
	{
		os << "Circle: "<<icircle.GetName().c_str()<<" {"<<icircle.GetCenter().GetPosition().c_str()<<", "<<icircle.GetRadius()<<"}, area = "<<icircle.GetArea();
		return os;
	}
private:
	Point m_center;
	double m_radius;
};

#endif