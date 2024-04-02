#pragma once
#include "Shapes.h"
class Triangle : public Shapes
{
public:
	Triangle();
	Triangle(double b, double h);
	double area() const override;
	double perimeter() const override;
	bool pointIsInsideTriangleOrNot(int triX1, int triX2, int triX3, int triY1, int triY2, int triY3, int inX, int inY);
private:
	double base, height;
	int triX1, triX2, triX3, triY1, triY2, triY3;
	int inX, inY;
};






	

