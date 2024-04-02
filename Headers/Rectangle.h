#pragma once

#include "Shapes.h"

class Rectangle : public Shapes
{
    public:
	Rectangle();
	Rectangle(double l, double w);
	double area() const override;
	double perimeter() const override;
	bool  pointIsInsideRectangleOrNot(int bottomLeftX, int bottomLeftY, int length, int width, int inX, int inY);

private:
	double length, width;
	int bottomLeftX, bottomLeftY;
	int inX, inY;
};



