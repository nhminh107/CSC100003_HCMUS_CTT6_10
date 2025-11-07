#pragma once

class Ellipse : public Shape {
private: 
	Point center; 
	float rX, rY; 
public: 
	Ellipse(); 
	~Ellipse();
	
	void Draw(sf::RenderWindow&) const override; 
	void updateAtt() override; 

	Point getCenter(); 
	float getRX();
	float getRY(); 
	
	void setCenter(const Point&); 
	void setCenter(float, float); 
	void setRX(float); 
	void setRY(float); 
};
