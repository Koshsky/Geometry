#include <iostream>
#include "Shape.h"
#include "Diamond.h"
#include "Rectangle.h"
#include "CompositeShape.h"
#include "Point.h"

using namespace std;

void testDiamond();
void testRectangle();
void testCompositeShape();


int main()
{
	testDiamond();
	testRectangle();
	testCompositeShape();
	return EXIT_SUCCESS;
}

void testDiamond()
{
	cout << "========================= DIAMOND TEST =========================\n";
	Diamond shp(Point(0, 0), 10, 5);
	cout << "Shape:\t\t" << shp << "\n\n";
	cout << "shp.move(Point(3, 3));\n";
	shp.move(Point(3, 3));
	cout << "Shape:\t\t" << shp << "\n\n";
	cout << "shp.scale(2);\n";
	shp.scale(2);
	cout << "Shape:\t\t" << shp << "\n\n";
	Diamond* shpClone = shp.clone();
	cout << "Clone test:\n";
	cout << "shp:\t\t" << &shp << ' ' << shp << '\n';
	cout << "shpClone:\t" << shpClone << ' ' << *shpClone << '\n';
	cout << "============================= END ==============================\n\n";
}

void testRectangle()
{
	cout << "======================== RECTANGLE TEST ========================\n";
	Rectangle shp(Point(0, 0), Point(6, 7));
	cout << "Shape:\t\t" << shp << "\n\n";
	cout << "shp.move(Point(0, 3));\n";
	shp.move(Point(0, 3));
	cout << "Shape:\t\t" << shp << "\n\n";
	cout << "shp.scale(2);\n";
	shp.scale(2);
	cout << "Shape:\t\t" << shp << "\n\n";
	Rectangle* shpClone = shp.clone();
	cout << "Clone test:\n";
	cout << "shp:\t\t" << &shp << ' ' << shp << '\n';
	cout << "shpClone:\t" << shpClone << ' ' << *shpClone << '\n';
	cout << "============================= END ==============================\n\n";

}


void testCompositeShape()
{
	cout << "===================== COMPOSITE_SHAPE TEST =====================\n";
	CompositeShape compShp = CompositeShape(2);
	Rectangle rect(Point(0, 0), Point(6, 7));
	Diamond diamond(Point(100, 100), 10, 5);
	compShp.append(rect).append(diamond);
	cout << "Shapes:\t\t" << rect << "\n\t\t" << diamond << "\n\n";
	cout << "compShp.move(Point(0, 0));\n";
	compShp.move(Point(0, 0));
	cout << "Shapes:\t\t" << rect << "\n\t\t" << diamond << "\n\n";
	cout << "compShp.scale(2);\n";
	compShp.scale(2);
	cout << "Shapes:\t\t" << rect << "\n\t\t" << diamond << "\n";
	cout << "============================= END ==============================\n\n";
}