#pragma once

class Shape {
protected:
	string firgure; 
	string text_name; 
	Stroke strokeColor; 
	Color fillColor; 
	string containData; 
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
};
