#include "main_menu.h"

//Main Menu Draw
void main_menu:: main_menu1()
{
	ofSetColor(0, 0, 0);
	ofDrawRectangle(0, 0, 640, 640);
	ofSetColor(192, 57, 43);
	ofDrawBitmapStringHighlight("RACING CAR", 220, 270, ofColor::red, ofColor::blue);
	ofDrawBitmapStringHighlight("PRESS X TO START", 200, 330, ofColor::red, ofColor::blue);
}

//Win Menu Draw
void main_menu::menu_win()
{
	ofSetColor(0, 0, 0);
	ofDrawRectangle(0, 0, 640, 640);
	ofSetColor(192, 57, 43);
	ofDrawBitmapStringHighlight("YOU WIN!", 220, 210, ofColor::white, ofColor::gold);
	ofDrawBitmapStringHighlight("RACING CAR", 220, 270, ofColor::red, ofColor::blue);
	ofDrawBitmapStringHighlight("PRESS X TO START", 200, 330, ofColor::red, ofColor::blue);
}
