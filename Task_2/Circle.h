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
private:
	virtual void ToStream(std::ostream& ostream) const
	{
		ostream<<"Circle: "<<GetName().c_str()<<" {"<<GetCenter().GetPosition().c_str();
		ostream<<", "<<GetRadius()<<"}, area = "<<GetArea();
	}
private:
	Point m_center;
	double m_radius;
};

#endif