#pragma once
#include "Shapes.h"

class Circle: public Shapes
{
public:
	Circle();
	Circle(double r);
	double area() const override;
	double perimeter() const override;
	bool pointIsInsideCircleOrNot(int centerX, int centerY, int inX, int inY, double radius);

private:
	double radius;
	int centerX, centerY, inX, inY;
};
