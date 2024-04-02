#include "Circle.h"
#include <iostream>
#include <cmath>


Circle::Circle() {
	
}

Circle::Circle(double r) : radius(r) {}

 

double Circle::area() const {
    return 3.14159 * radius * radius; // Approximation of pi
}

double Circle::perimeter() const {
    return 2 * 3.14159 * radius; // Approximation of pi
}

bool Circle ::  pointIsInsideCircleOrNot(int centerX, int centerY, int inX, int inY, double radius) {
   
    double distance = sqrt(pow(inX - centerX, 2) + pow(inY - centerY, 2));

    return (distance <= radius);
 
}






