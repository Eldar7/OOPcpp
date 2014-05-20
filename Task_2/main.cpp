#include "Named.h"
#include "Printable.h"
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Rect.h"
#include "Square.h"
#include "Polyline.h"

int main()
{
	std::cout<<Shape::GetCount()<<std::endl; //0

	XList<Shape*>* shlist = new XList<Shape*>;
	Point* point0 = new Point("simple_point");
	Point* point1 = new Point(1,1);
	Point* point2 = new Point(-2.2,2);
	Circle* circle = new Circle("bublic", *point0,5);
	Rect* rect1 = new Rect(*point1, *point2);
	Square* square = new Square(*point0, *point1);
	Rect* rect2 = new Rect(*square);
	Polyline* pl = new Polyline;
	pl->AddPoint(*point0);
	pl->AddPoint(*point1);
	pl->AddPoint(*point2);

	circle->Print();

	std::cout<<Shape::GetCount()<<std::endl; //18

	shlist->push_back(point0);
	shlist->push_back(rect2);
	shlist->push_back(circle);
	shlist->push_front(rect1);
	shlist->push_back(square);
	shlist->push_back(pl);
	shlist->push_back(point2);
	shlist->push_front(point1);

	std::cout<<Shape::GetCount()<<std::endl; //18

	for (XList<Shape*>::iterator it = shlist->begin(); it != shlist->end(); ++it)
	{
		std::cout<<**it<<std::endl;
	}
	std::cout<<Shape::GetCount()<<std::endl; //18
	
	for (XList<Shape*>::iterator it = shlist->begin(); it != shlist->end(); ++it)
	{
		delete *it;
	}
	std::cout<<Shape::GetCount()<<std::endl; //0

	delete shlist;
	return 0;
}