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
	Point smth(-1,1);
	Point smth2(smth), point(0,2);
	point.Print();

	Circle cir("cir", smth, 3);
	cir.Print();

//	Circle* pnt = new Circle;
//	delete pnt;

	Rect rect("rect", point, smth);
	rect.Print();
//	rect.Print();
	Square* sq = NULL;
	try
	{
		Point a(1,1);
		Point b(3,3);
		sq = new Square("ABBA", a, b);
		sq->Print();
		std::cout<<*sq<<std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
//	delete sq;

	std::cout<<std::endl;
	Circle cir2(cir);
	cir2.Print();
	Rect rect2(rect);
	rect2.Print();
	Square sq2(*sq);
//	delete sq;
	sq2.Print();

	std::cout<<std::endl;
	Polyline pl("pl");
	pl.AddPoint(smth);
	pl.AddPoint(point);
	pl.AddPoint(smth);
	pl.Print();
	std::cout<<pl<<std::endl;

	Polyline* pln = new Polyline("pln");
	pln->AddPoint(point);
	pln->AddPoint(point);
	pln->AddPoint(point);
	pln->Print();

	Shape nmd("asd");
	nmd.Rename("asdasdas");
	std::cout<<cir<<std::endl;
	std::cout<<rect2<<std::endl;
	std::cout<<(*sq)<<std::endl;
	std::cout<<(*pln)<<std::endl;
	rect2.Print();

	std::cout<<Shape::GetCount()<<std::endl;

	delete pln;
//	std::cout<<(*pln)<<std::endl;

	delete sq;
//	std::cout<<(*sq)<<std::endl;

	std::cout<<Shape::GetCount()<<std::endl;

	Named *myshape = new Point(0,0);
	delete myshape;
	std::cout<<Shape::GetCount()<<std::endl;
	
	return 0;
}