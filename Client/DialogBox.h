#pragma once
#include "Base.h"
class DialogBox :
	public Base
{
public:
	std::string vtitle = "";
	std::string vtext = "";
	int vheight = 30;
	int vwidth = 100;
	DialogBox(std::string text);
	DialogBox(std::string text, std::string title);
	DialogBox(std::string text, int size);
	DialogBox(std::string text, int height, int width);
	DialogBox(std::string text, std::string title, int size);
	DialogBox(std::string text, std::string title, int height, int width);
	~DialogBox();
	void Draw(sf::RenderWindow &);
	void Initilize();
};

