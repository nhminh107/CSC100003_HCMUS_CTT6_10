#include "Library.h"
using namespace std; 

Stroke::Stroke() {
	this->strokeWidth = 0;
}

Stroke::~Stroke() {
	this->strokeWidth = 0;
}



void Stroke::setStrokeColor(const Color& col) {
	this->strokeColor = col;
}

void Stroke::setStrokeWidth(float width) {
	this->strokeWidth = width;
}