#pragma once
#include "ofMain.h"
class car
{
public:
	//Car Settings\Config
	int x;
	int y;
	int width;
	int height;
	int radius;
	int car_center_x;
	int car_center_y;

	int ox;
	int oy;
	ofColor colors[2] = { ofColor::red, ofColor::blue};
	void setupP();
	void setupO();
	void drawCar();
	void drawoCar();
};

