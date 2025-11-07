#pragma once

class Color {
private: 
public: 
	int r, g, b, a; 
	Color() {
		r = g = b = a = -1; 
	}
};

class Stroke {
private: 
	Color strokeColor; 
	float strokeWidth; 
public: 
	Stroke(); 
	~Stroke(); 

	void setStrokeColor(const Color&); 
	void setStrokeWidth(float); 
	Color getStrokeColor() const { return strokeColor; }
	float getStrokeWidth() const { return strokeWidth; }
};