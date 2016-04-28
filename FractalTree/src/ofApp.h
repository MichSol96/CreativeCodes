#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

/*
Project 1
Michelle Solon
	This project generates fractal trees based on the current x,y position of the mouse. It uses a thetha value to spread the branches out. The thetha value is taken from a csv that tracked my CPU temperature. The mouse is hidden when it's on the screen so moving the mouse around will appear to randomly generate the trees on the canvas. The tree's have an alpha value that is also based on mouse x, y; the further down and to the right you get, the more opaque the trees become. The background refresh rate is turned off so the trees stamp themselves over the screen. 
*/
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void recursiveTree(float level);
	void branch(float len);

	int treeX, treeY, r, g, b, randNum, x, y;
	float thetha, temp, a;
	ofMesh mesh;
	ofxCsvRow row;

	ofxCsv csv;
};