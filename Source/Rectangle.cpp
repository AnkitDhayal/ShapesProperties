#include "Rectangle.h"
#include <iostream>


Rectangle::Rectangle()
{

};

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

double Rectangle::area() const {
    return length * width;
}

double Rectangle::perimeter() const {
    return 2 * (length + width);
}

bool Rectangle:: pointIsInsideRectangleOrNot(int bottomLeftX, int bottomLeftY, int length, int width, int inX, int inY) {
    int recX1 = bottomLeftX;
    int recY1 = bottomLeftY;
    int recX2 = bottomLeftX + length;
    int recY2 = bottomLeftY;
    int recX3 = bottomLeftX + length;
    int recY3 = bottomLeftY + width;
    int recX4 = bottomLeftX;
    int recY4 = bottomLeftY + width;

    // Check if the point is within the bounding box of the rectangle
    if (inX >= std::min(recX1, std::min(recX2, std::min(recX3, recX4))) &&
        inX <= std::max(recX1, std::max(recX2, std::max(recX3, recX4))) &&
        inY >= std::min(recY1, std::min(recY2, std::min(recY3, recY4))) &&
        inY <= std::max(recY1, std::max(recY2, std::max(recY3, recY4)))) {

        // Calculate the cross product of vectors from the input point to each pair of adjacent rectangle vertices
        int crossProduct1 = (inX - recX1) * (recY2 - recY1) - (inY - recY1) * (recX2 - recX1);
        int crossProduct2 = (inX - recX2) * (recY3 - recY2) - (inY - recY2) * (recX3 - recX2);
        int crossProduct3 = (inX - recX3) * (recY4 - recY3) - (inY - recY3) * (recX4 - recX3);
        int crossProduct4 = (inX - recX4) * (recY1 - recY4) - (inY - recY4) * (recX1 - recX4);

        // Check if all cross products have the same sign
        if ((crossProduct1 >= 0 && crossProduct2 >= 0 && crossProduct3 >= 0 && crossProduct4 >= 0) ||
            (crossProduct1 <= 0 && crossProduct2 <= 0 && crossProduct3 <= 0 && crossProduct4 <= 0)) {
            // Point is inside or on the boundary of the rectangle
            return true;
        }
    }
    return false;
}