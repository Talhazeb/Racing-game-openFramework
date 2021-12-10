#include "car.h"

//Player car Initializations
void car::setupP()
{
	x = 170;
	y = 500;
	width = 10;
	height = 15;
	radius = 7.0;
}

//Opponent car Initializations
void car::setupO()
{
	ox = 170;
	oy = 0;
	width = 10;
	height = 15;
	radius = 7.0;
}

//Drawing Player Car
void car::drawCar()
{
	ofSetColor(0, 0, 255);
	ofDrawRectRounded(x, y, width, height, radius); // bottom left tyre
	ofDrawRectRounded(x + width * 3, y, width, height, radius); // bottom right tyre
	ofDrawRectRounded(x + width * 3, y + height * 4, width, height, radius); // top right tyre
	ofDrawRectRounded(x, y + height * 4, width, height, radius); // top left tyre
	ofDrawRectRounded(x + width, y + height, width * 2, height * 3, radius / 2); // body center rect
}

//Drawing Opponents Car
void car::drawoCar()
{
	ofSetColor(255, 0, 0);
	ofDrawRectRounded(ox, oy, width, height, radius); // bottom left tyre
	ofDrawRectRounded(ox + width * 3, oy, width, height, radius); // bottom right tyre
	ofDrawRectRounded(ox + width * 3, oy + height * 4, width, height, radius); // top right tyre
	ofDrawRectRounded(ox, oy + height * 4, width, height, radius); // top left tyre
	ofDrawRectRounded(ox + width, oy + height, width * 2, height * 3, radius / 2); // body center rect
}