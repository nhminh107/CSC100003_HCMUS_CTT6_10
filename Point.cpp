#include "Libary.h"
using namespace std;

Point::Point() {
	x = 0; 
	y = 0; 
	intersect = false; 
}
Point::Point(float xPoint, float yPoint) : x(xPoint), y(yPoint), intersect(false) {};

float Point::getX() const  { return x;}
float Point::getY() const { return y;} 
bool Point::getIntersect() const { return intersect; }

void Point::setX(float xPoint) { x = xPoint;  }
void Point::setY(float yPoint) { y = yPoint;  }
void Point::setIntersect(bool its) { intersect = its; }

bool Point::operator==(const Point& other) {
	return (this->x == other.x) && (this->y == other.y); 
}
