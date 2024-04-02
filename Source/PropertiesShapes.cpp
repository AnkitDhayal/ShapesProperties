// PropertiesShapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "fstream"

enum ShapeType {
	RECTANGLE,
	CIRCLE,
	TRIANGLE
};

int main()
{
	std::cout << "Hello World!\n";
	int n, choice;
	double rad, len, wid, b, h;
	int tX1, tX2, tX3, tY1, tY2, tY3;
	int bottomLeftX, bottomLeftY;
	int cX1, cY1, cRad;
	int inputX, inputY;
	int temp = 0;
	std::cout << "what you want to do : 1.Find out that the point is inside which shape   2. Find out the area and perimter for different shapes  3. Want to show on the gnu plot and check whether it lies or not " << std::endl;
	std::cin >> choice;


	if (choice == 1) {
		//code for inside point validation


		//Getting Triangle Coordinates
		std::cout << "enter the coordinate of traingle first point" << std::endl;
		std::cin >> tX1 >> tY1;
		std::cout << "enter the coordinate of traingle second point" << std::endl;
		std::cin >> tX2 >> tY2;
		std::cout << "enter the coordinate of traingle third point" << std::endl;
		std::cin >> tX3 >> tY3;

		//Getting Rectangle Coodinates
		std::cout << "enter the coordinate of rectangle bottomLeft point" << std::endl;
		std::cin >> bottomLeftX >> bottomLeftY;
		std::cout << "enter the length and width" << std::endl;
		std::cin >> len >> wid;


		//Getting Circle Coordinates
		std::cout << "enter the coordinate of center of circle" << std::endl;
		std::cin >> cX1 >> cY1;
		std::cout << "enter the radius of circle " << std::endl;
		std::cin >> cRad;

		//Taking Input Points From User
		std::cout << "Enter the Points which you want to Check " << std::endl;
		std::cin >> inputX >> inputY;

		Circle circle;
		Rectangle rectangle;
		Triangle triangle;
		if (circle.pointIsInsideCircleOrNot(cX1, cY1, inputX, inputY, cRad) == 1) {
			std::cout << "This point lie inside the circle " << std::endl;
			temp++;
		}

		if (rectangle.pointIsInsideRectangleOrNot(bottomLeftX, bottomLeftY, len, wid, inputX, inputY) == 1) {
			std::cout << " This point lie inside the rectangle " << std::endl;
			temp++;
		}

		if (triangle.pointIsInsideTriangleOrNot(tX1, tX2, tX3, tY1, tY2, tY3, inputX, inputY) == 1) {
			std::cout << "This point lie inside the rectangle " << std::endl;
			temp++;
		}
		if (temp == 0) {
			std::cout << "The point does not lie in any of the shape" << std::endl;
		}

	}
	else if (choice == 2) {
		std::cout << "Enter the number  for the shapes 1.Rectangle  2. Circle  3.Triangle" << std::endl;
		std::cin >> n;
		ShapeType shapeType;
		switch (n) {
		case 1:
			shapeType = RECTANGLE;
			break;
		case 2:
			shapeType = CIRCLE;
			break;
		case 3:
			shapeType = TRIANGLE;
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			return 0;
		}
		switch (shapeType) {
		case RECTANGLE: {
			double length, width;
			std::cout << "Enter length and width of rectangle: ";
			std::cin >> length >> width;
			Rectangle rectangle(length, width);
			std::cout << "Rectangle Area: " << rectangle.area() << std::endl;
			std::cout << "Rectangle Perimeter: " << rectangle.perimeter() << std::endl;
			break;
		}
		case CIRCLE: {
			double radius;
			std::cout << "Enter radius of circle: ";
			std::cin >> radius;
			Circle circle(radius);
			std::cout << "Circle Area: " << circle.area() << std::endl;
			std::cout << "Circle Perimeter: " << circle.perimeter() << std::endl;
			break;
		}
		case TRIANGLE: {
			double base, height;
			std::cout << "Enter base and height of triangle: ";
			std::cin >> base >> height;
			Triangle triangle(base, height);
			std::cout << "Triangle Area: " << triangle.area() << std::endl;
			std::cout << "Triangle Perimeter: " << triangle.perimeter() << std::endl;

			break;
		}
		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
	else if (choice == 3) {
		std::cout << "which shape 1. Rectangle 2.Circle 3.Triangle" << std::endl;
		std::cin >> n;
		ShapeType shapeType;
		switch (n) {
		case 1:
			shapeType = RECTANGLE;
			break;
		case 2:
			shapeType = CIRCLE;
			break;
		case 3:
			shapeType = TRIANGLE;
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			return 0;
		}
		switch (shapeType) {
		case RECTANGLE:
		{
			std::cout << "enter the bottomLeft point Coodinates" << std::endl;
			std::cin >> bottomLeftX >> bottomLeftY;
			std::cout << "Enter the length and width " << std::endl;
			std::cin >> len >> wid;
			int recX1 = bottomLeftX;
			int recY1 = bottomLeftY;
			int recX2 = bottomLeftX + len;
			int recY2 = bottomLeftY;
			int recX3 = bottomLeftX + len;
			int recY3 = bottomLeftY + wid;
			int recX4 = bottomLeftX;
			int recY4 = bottomLeftY + wid;
			std::cout << "Enter the input point" << std::endl;
			std::cin >> inputX >> inputY;

			std::ofstream MyFile("D://Ankit_Workspace//OutputFileForShapes//Shape.txt");
			MyFile << recX1 << " " << recY1 << std::endl;
			MyFile << recX2 << " " << recY2 << std::endl;
			MyFile << recX3 << " " << recY3 << std::endl;
			MyFile << recX4 << " " << recY4 << std::endl;
			MyFile << recX1 << " " << recY1 << std::endl;
			MyFile.close();

			std::ofstream MyFile1("D://Ankit_Workspace//OutputFileForShapes//Input.txt");
			MyFile1 << inputX << " " << inputY << std::endl;
			MyFile1.close();
			std::cout << "Output file has been created load on gnu plot" << std::endl;

			break;
		}
		case TRIANGLE:
		{
			std::cout << "Enter the first corrdinates of triangle" << std::endl;
			std::cin >> tX1 >> tY1;
			std::cout << "Enter the second corrdinates of triangle" << std::endl;
			std::cin >> tX2 >> tY2;
			std::cout << "Enter the third corrdinates of triangle" << std::endl;
			std::cin >> tX3 >> tY3;
			std::cout << "Enter the input point" << std::endl;
			std::cin >> inputX >> inputY;



			std::ofstream MyFile("D://Ankit_Workspace//OutputFileForShapes//Shape.txt");
			MyFile << tX1 << " " << tY1 << std::endl;
			MyFile << tX2 << " " << tY2 << std::endl;
			MyFile << tX3 << " " << tY3 << std::endl;
			MyFile << tX1 << " " << tY1 << std::endl;
			MyFile.close();

			std::ofstream MyFile1("D://Ankit_Workspace//OutputFileForShapes//Input.txt");
			MyFile1 << inputX << " " << inputY << std::endl;
			MyFile1.close();
			std::cout << "Output file has been created load on gnu plot" << std::endl;
			break;
		}
		case CIRCLE :{
			std::cout << "Enter the center corrdinates of circle" << std::endl;
			std::cin >> cX1 >> cY1;
			std::cout << "Enter the radius of circle" << std::endl;
			std::cin >> cRad;
			std::cout << "Enter the input point" << std::endl;
			std::cin >> inputX >> inputY;

			std::ofstream MyFile("D://Ankit_Workspace//OutputFileForShapes//Shape.txt");
			int theta = 0;
			for (int i = 0; theta <= 360; i++) {
				double resultX = cX1 + cRad * cos(i);
				double resultY = cY1 + cRad * sin(i);
				MyFile << resultX<< " " << resultY << std::endl;
				theta++;
			}
			
			MyFile.close();

			std::ofstream MyFile1("D://Ankit_Workspace//OutputFileForShapes//Input.txt");
			MyFile1 << inputX << " " << inputY << std::endl;
			MyFile1.close();
			std::cout << "Output file has been created load on gnu plot" << std::endl;

			break;
		}
		default:
			std::cout << "invalid choice" << std::endl;

		}
	}

	else {
		std::cout << "invalid choice" << std::endl;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
