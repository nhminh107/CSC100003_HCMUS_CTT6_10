#include "Library.h"
using namespace std;


Ellipse::Ellipse() :Shape() {
	rX = rY = 0;
	center.setX(0);
	center.setY(0);
}

Ellipse::~Ellipse() {
	rX = rY = 0;
	center.setX(0);
	center.setY(0);
}

void Ellipse::updateAtt() {
	stringstream ss(line);
	string property, value;

	while (ss >> property >> value) {
		if (property == "rx")
			this->rX = stof(value);
		if (property == "ry")
			this->rY = stof(value);
		if (property == "cx")
			this->center.setX(stof(value));
		if (property == "cy")
			this->center.setY(stof(value));
	}
}

Point Ellipse::getCenter() {
	return this->center;
}

float Ellipse::getRX() {
	return this->rX;
}

float Ellipse::getRY() {
	return this->rY;
}

void Ellipse::setCenter(float x, float y) {
	this->center.setX(x);
	this->center.setY(y);
}

void Ellipse::setRX(float rx) {
	this->rX = rx;
}

void Ellipse::setRY(float ry) {
	this->rY = ry;
}

void Ellipse::Draw(sf::RenderWindow& window) const {
	unsigned short pointNum = 72; //72 is the golden distribution of points to form ellipse

	sf::ConvexShape ellipse;
	ellipse.setPointCount(pointNum);

	for (unsigned short i = 0; i < pointNum; i++) {
		float radian = (360 / pointNum * i) / (180 / M_PI);
		float x = cos(radian) * rX;
		float y = sin(radian) * rY;

		ellipse.setPoint(i, sf::Vector2f(x, y));
	}

	if (fillColor.r != -1) {
		ellipse.setFillColor(sf::Color(fillColor.r, fillColor.g, fillColor.b));
		if (fillColor.a >= 0)
			ellipse.setFillColor(sf::Color(fillColor.r, fillColor.g, fillColor.b, fillColor.a * MAX));
	}
	else ellipse.setFillColor(sf::Color::Transparent);

	if (strokeColor.getStrokeColor().r != -1) {
		ellipse.setOutlineColor(sf::Color(strokeColor.getStrokeColor().r, strokeColor.getStrokeColor().g, strokeColor.getStrokeColor().b));
		ellipse.setOutlineThickness(strokeColor.getStrokeWidth());
		if (strokeColor.getStrokeColor().a >= 0)
			ellipse.setOutlineColor(sf::Color(strokeColor.getStrokeColor().r, strokeColor.getStrokeColor().g, strokeColor.getStrokeColor().b, strokeColor.getStrokeColor().a* MAX));
	}
	else ellipse.setOutlineColor(sf::Color::Transparent);

	if (this->text_name == "ellipse")
		ellipse.setPosition(center.getX(), center.getY() - 10);
	else ellipse.setPosition(center.getX() - 10, center.getY());

	window.draw(ellipse);
}