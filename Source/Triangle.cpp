#include "Triangle.h"
#include <iostream>


Triangle::Triangle() {

}


Triangle::Triangle(double b, double h) : base(b), height(h) {}

double Triangle::area() const {
    return 0.5 * base * height; 
}
double Triangle::perimeter() const {
	return 3 * base;
}

bool Triangle ::pointIsInsideTriangleOrNot(int triX1, int triX2, int triX3, int triY1, int triY2, int triY3, int inX, int inY) {
    // Calculate the barycentric coordinates of the point
    float denominator = ((triY2 - triY3) * (triX1 - triX3) + (triX3 - triX2) * (triY1 - triY3));
    float lambda1 = ((triY2 - triY3) * (inX - triX3) + (triX3 - triX2) * (inY - triY3)) / denominator;
    float lambda2 = ((triY3 - triY1) * (inX - triX3) + (triX1 - triX3) * (inY - triY3)) / denominator;
    float lambda3 = 1.0f - lambda1 - lambda2;

    // Check if the point lies within the triangle using barycentric coordinates
    if (lambda1 >= 0 && lambda2 >= 0 && lambda3 >= 0) {
        // Point is inside the triangle
        return true;
    }
    else {
        // Point is outside the triangle
        return false;
    }
}


