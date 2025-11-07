#pragma once

class Point {
private: 
	float x, y; 
	bool intersect; 
public: 
	Point(); 
	Point(float, float); 
	float getX() const;
	float getY() const;
	bool getIntersect() const;

	void setX(float); 
	void setY(float); 
	void setIntersect(bool); 

	bool operator==(const Point&); 
};