#include "ofApp.h"
#include <vector>
#include <time.h>
#include <cstdlib>
#include <Windows.h> //for sleep


long long int counter = 0;
long long int counter2 = 0;
bool pass = false;
bool statusmenu=true;
bool statuswin = false;
int lives = 3;
int score = 0;
vector<int> v1 = vector<int>();

//--------------------------------------------------------------
void ofApp::setup(){
	//Smooth Framerate
	ofSetFrameRate(60);
	ofSetBackgroundColor(0, 0, 0);
	//Music Integration Background
	mySound.load("music.wav");
	mySound.play();

	//Middle road blocks placement
	for (int i = 0; i < 640; i += 25)
	{
		v1.push_back(i);
	}
	//Setting Car setup
	playerCar.setupP();
	opCar.setupO();

}


//--------------------------------------------------------------
void ofApp::update(){
	
	//Game Logic Main
	if (statusmenu == false || statuswin == false)
	{
		//Middle road blocks movement to simulate car movement in real time. each block will be placed and increamted in
		//next interval and again setting the interval back to 0 to make middle road blocks displacement after each interval.
		for (int i = 0; i < v1.size(); i++)
		{
			v1[i] = v1[i] + 5;//displacement changed
		}
		if (v1[(v1.size() - 1)] > 650)
		{
			v1.pop_back();
			v1.insert(v1.begin(), 0);//displacement back to 0
		}
		opCar.oy += 5;
		//Random car generation of opponent after each opponent leaves window size
		if (opCar.oy == 660)
		{
			srand(time(0));
			int random = rand() % 5 + 1;
			counter = random * 10;
			pass = true;
			score++;
		}
		//Win Score
		if (score == 20)
		{
			statuswin = true;
		}
		//Car generation counter
		if (pass == true)
		{
			counter2++;
		
		}
		//Setting opponent car positon based on randomness and logic
		if (counter2 == counter && pass == true)
		{
			pass = false;
			opCar.oy = 0;
			counter2 = 0;
			srand(time(0));
			int lane = rand() % 2;
			if (lane == 0)//left lane
			{
				opCar.ox = 170;
			}
			else if (lane == 1)//right lane
			{
				opCar.ox = 300;
			}
		}
		//Car collision
		if (opCar.oy + opCar.height == playerCar.y)
		{
			if (opCar.ox == playerCar.x)
			{
				playerCar.setupP();
				opCar.setupO();
				lives--; // decrement lives and reset positions
				
				//delay for next live
				Sleep(800);//800 millisecond
				if (lives == 0)
				{
					//lose condition all reset and go back to menu
					lives = 3;
					score = 0;
					statusmenu=true;
				}
			}

		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	//Draw game only if not in menu
	if (!statusmenu && !statuswin)
	{
		//left and right path
		ofSetColor(255, 255, 0);
		for (int i = 0; i < 640; i++)
		{
			ofDrawRectangle(125, i, 10, 10);
		}
		for (int i = 0; i < 640; i++)
		{
			ofDrawRectangle(375, i, 10, 10);
		}
		//middle blocks
		int count = 0;
		for (int i = 0; i < v1.size(); i++)
		{
			ofSetColor(255, 255, 255);
			ofDrawRectangle(250, v1.at(i), 10, 15);
		}

		//Side Greenery
		ofSetColor(0, 153, 0);
		ofDrawRectangle(0, 0, 125, 640);
		ofSetColor(0, 153, 0);
		ofDrawRectangle(385, 0, 125, 640);

		//Movement Instructions Drawing
		ofDrawBitmapStringHighlight("W to move up", 1, 100, ofColor::white, ofColor::black);
		ofDrawBitmapStringHighlight("S to move down", 1, 130, ofColor::white, ofColor::black);
		ofDrawBitmapStringHighlight("A to move left", 1, 160, ofColor::white, ofColor::black);
		ofDrawBitmapStringHighlight("D to move right", 1, 190, ofColor::white, ofColor::black);

		//Lives Display
		ofDrawBitmapStringHighlight("LIVES:", 420, 100, ofColor::white, ofColor::black);
		string st_lives = to_string(lives);
		ofDrawBitmapStringHighlight(st_lives, 470, 100, ofColor::white, ofColor::black);

		//Score Display
		ofDrawBitmapStringHighlight("SCORE:", 420, 150, ofColor::white, ofColor::black);
		string st_score = to_string(score);
		ofDrawBitmapStringHighlight(st_score, 470, 150, ofColor::white, ofColor::black);

		//Cars Drawing
		playerCar.drawCar();
		opCar.drawoCar();
	
	}
	else if(statuswin == true)
	{
		//if win then show win menu and not draw
		m.menu_win();
		score = 0;
		lives = 3;
	}
	else
	{
		m.main_menu1();
		score = 0;
		lives = 3;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') // 'w' key
	{
		playerCar.y-=5;
	}
	if (key == 'a') // 'a' key
	{
		if (playerCar.x == 300)
		{
			playerCar.x = 170;
		}
	}
	if (key == 's') // 's' key
	{
		playerCar.y+= 5;
	}
	if (key == 'd') // 'd' key
	{
		if (playerCar.x == 170)
		{
			playerCar.x = 300;
		}
	}
	if (key == 'x')//Starting game
	{
		statusmenu = false;
		statuswin = false;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
