#pragma once

class Point {
private: 
	float x, y; 
	bool intersect; 
public: 
	Point(); 
	Point(float, float); 
	float getX; 
	float getY; 
	bool getIntersect(); 

	void setX(float); 
	void setY(float); 
	void setIntersect(); 

	bool operator==(const Point&); 
};