#include "DialogBox.h"



DialogBox::DialogBox(std::string text)
{
	vtext = text;
}

DialogBox::DialogBox(std::string text, std::string title)
{
	vtext = text;
	vtitle = title;
}

DialogBox::DialogBox(std::string text, int size)
{
	vtext = text;
	vheight = size;
	vwidth = size;
}

DialogBox::DialogBox(std::string text, int height, int width)
{
	vtext = text;
	vheight = height;
	vwidth = width;
}

DialogBox::DialogBox(std::string text, std::string title, int size)
{
	vtext = text;
	vtitle = title;
	vheight = size;
	vwidth = size;
}

DialogBox::DialogBox(std::string text, std::string title, int height, int width)
{
	vtext = text;
	vtitle = title;
	vheight = height;
	vwidth = width;
}

DialogBox::~DialogBox()
{
}

void DialogBox::Draw(sf::RenderWindow &window) {

}

void Initialize() {

}
