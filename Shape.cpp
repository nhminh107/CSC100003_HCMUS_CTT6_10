#include "Library.h"
using namespace std;

/*class Shape {
protected:
	string firgure; 
	string text_name; 
	Stroke strokeColor; 
	Color fillColor; 
	string line; 
	unordered_map<string, Color> mapCol; 
	
	void loadColor(); 
	Color processColor(string, string); 
public: 
	Shape();
	void update(string, string, string);
	void updateElement(string, string, string);
	virtual void updateAtt();

	string getName();
	void setName(string);

	virtual ~Shape();
	virtual void Draw(sf::RenderWindow&) const;
};*/
Shape::Shape() {
	line = figure = text_name = "";
	this->strokeColor; 
	this->fillColor; 
	loadColor(); 
};
void Shape::loadColor() {
	ifstream color_file("Color.txt", ios::in);

	if (!color_file.is_open()) {
		cout << "Error Loading Color File\n";
		return;
	}

	string color_line = "";
	while (getline(color_file, color_line)) {
		int pos = color_line.find("#");
		stringstream ss(color_line);
		string token = "";
		vector<string> vct;

		while (ss >> token)
			vct.push_back(token);

		string color_name, hexa_code;
		int n = vct.size();

		for (int i = 0; i < n - 1; i++)
			color_name = color_name + vct[i];

		hexa_code = vct[n - 1];
		Color color;
		color.r = stoi(hexa_code.substr(1, 2), NULL, 16);
		color.g = stoi(hexa_code.substr(3, 2), NULL, 16);
		color.b = stoi(hexa_code.substr(5, 2), NULL, 16);

		mapCol[color_name] = color;
	}
	mapCol["none"] = Color();
}

void Shape::updateElement(string figure, string attribute, string text_name) {
	this->line = attribute;
	this->figure = figure;
	this->text_name = text_name;

	stringstream ss(line);
	string property, value;
	string fillcolor = "", fillopa = "-1";
	string strokecolor = "", strokeopa = "-1";

	while (ss >> property >> value) {
		if (property == "stroke-width")
			this->strokeColor.setStrokeWidth(stof(value));
		if (property == "fill-opacity")
			fillopa = value;
		if (property == "fill")
			fillcolor = value;
		if (property == "stroke")
			strokecolor = value;
		if (property == "stroke-opacity")
			strokeopa = value;
	}

	this->fillColor = processColor(fillcolor, fillopa);
	this->strokeColor.setStrokeColor(processColor(strokecolor, strokeopa));
}
void Shape::update(string name, string att, string text_name) {
	updateElement(name, att, text_name);
	updateAtt(); 
}
void Shape::updateAtt() {}

Color Shape::processColor(string strokecolor, string strokeopa) {
	if (strokecolor.find("rgb") != string::npos) {
		Color color;
		color.a = stof(strokeopa);
		for (int i = 0; i < strokecolor.size(); i++) {
			if (!isdigit(strokecolor[i]))	//If the character is not number then change to ' '
				strokecolor[i] = ' ';
		}
		stringstream ss(strokecolor);
		string r, g, b;
		ss >> r >> g >> b;
		color.r = stof(r); color.g = stof(g); color.b = stof(b);
		ss.ignore();
		return color;
	}
	else {
		//If the color property is Color
		Color color = mapCol[strokecolor];
		color.a = stof(strokeopa);
		return color;
	}
}

string Shape::getName() {
	return this->figure;
}

void Shape::setName(string s) {
	this->figure = s;
}

Shape:: ~Shape() {}

void Shape::Draw(sf::RenderWindow& window) const {
	return;
}