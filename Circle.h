#pragma once

class Circle:public Shape {
private: 
	float radius;
	Point center; 
public:
	Circle(); 
	~Circle(); 
	void updateAtt() override; 
	void Draw(sf::RenderWindow&) const override;

	Point getCenter() const;
	float getRadius() const;
	void setCenter(float, float);
	void setCenter(const Point&);
	void setRadius(float); 
};