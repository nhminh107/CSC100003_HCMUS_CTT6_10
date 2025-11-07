#include "Library.h"
using namespace std;

Circle::Circle(): center(Point(0, 0)), radius(0) {} 
Circle::~Circle() {}
void Circle::updateAtt() {
	stringstream ss(line); 
	string att, value; 
	while (ss >> att >> value) {
		if (att == "r") this->radius = stof(value); 
		if (att == "cx") this->center.setX(stof(value)); 
		if (att == "cy") this->center.setY(stof(value)); 
	}
}
void Circle::Draw(sf::RenderWindow& window) const {
	sf::CircleShape circle;
	/*Cách 1: Convex: Nếu vẽ lỗi thì dùng: 
	unsigned short pointNum = 72; //72 is the golden distribution of points to form ellipse

	sf::ConvexShape ellipse;
	ellipse.setPointCount(pointNum);

	for (unsigned short i = 0; i < pointNum; i++) {
		float radian = (360 / pointNum * i) / (180 / Pi);
		float x = cos(radian) * rx;
		float y = sin(radian) * ry;

		ellipse.setPoint(i, sf::Vector2f(x, y));
	}

	if (fill.r != -1) {
		ellipse.setFillColor(sf::Color(fill.r, fill.g, fill.b));
		if (fill.opacity >= 0)
			ellipse.setFillColor(sf::Color(fill.r, fill.g, fill.b, fill.opacity * MAX));
	}
	else ellipse.setFillColor(sf::Color::Transparent);

	if (stroke.getStrokeColor().r != -1) {
		ellipse.setOutlineColor(sf::Color(stroke.getStrokeColor().r, stroke.getStrokeColor().g, stroke.getStrokeColor().b));
		ellipse.setOutlineThickness(stroke.getStrokeWidth());
		if (stroke.getStrokeColor().opacity >= 0)
			ellipse.setOutlineColor(sf::Color(stroke.getStrokeColor().r, stroke.getStrokeColor().g, stroke.getStrokeColor().b, stroke.getStrokeColor().opacity * MAX));
	}
	else ellipse.setOutlineColor(sf::Color::Transparent);

	if (this->getName() == "ellipse")
		ellipse.setPosition(center.getX(), center.getY() - 10);
	else ellipse.setPosition(center.getX() - 10, center.getY());

	window.draw(ellipse);
	*/

	/*=====cách 2 ======*/ 
	if (fillColor.r != -1) {
		circle.setFillColor(sf::Color(fillColor.r, fillColor.g, fillColor.b)); 
		if (fillColor.a >= 0) {
			circle.setFillColor(sf::Color(fillColor.r, fillColor.g, fillColor.b, fillColor.a * MAX)); 
		}
	}
	else circle.setFillColor(sf::Color::Transparent); 

	if (strokeColor.getStrokeColor().r != -1) {
		Color tmp = strokeColor.getStrokeColor(); 
		circle.setOutlineColor(sf::Color(tmp.r, tmp.g, tmp.b)); 
		circle.setOutlineThickness(strokeColor.getStrokeWidth()); 
		if (tmp.a >= 0) {
			circle.setOutlineColor(sf::Color(tmp.r, tmp.g, tmp.b, tmp.a * MAX));
		}
	}
	circle.setRadius(radius); 
	circle.setPosition(center.getX() * 1.0f, center.getY() * 1.0f); 
	window.draw(circle); 
}

Point Circle::getCenter() const{
	return center;
}

float Circle::getRadius() const { return radius;  }
void Circle::setCenter(float xPoint, float yPoint) {
	center.setX(xPoint); 
	center.setY(yPoint); 
	center.setIntersect(false); 
}
void Circle::setCenter(const Point& p) {
	center.setX(p.getX()); 
	center.setY(p.getY()); 
	center.setIntersect(p.getIntersect());
}
void Circle::setRadius(float r) {
	radius = r; 
}
