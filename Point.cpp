#include "Libary.h"
using namespace std;

Point::Point() {
	x = 0; 
	y = 0; 
	intersect = false; 
}
Point::Point(float xPoint, float yPoint) : x(xPoint), y(yPoint), intersect(false) {};