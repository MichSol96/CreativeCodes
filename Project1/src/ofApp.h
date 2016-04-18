#pragma once

#include "ofMain.h"


class Turtle {
	double myX;
	double myY;
	double myDirection;
	bool penDown;

	ofMesh mesh;

public:
	void setValues(int, int, double);
	void moveForward();
	void moveBackward();
	void turnLeft(double);
	void turnRight(double);
	void setPen(bool);
	double getMyX();
	double getMyY();
	double getMyDir();
	ofMesh getMesh();
	string dragonCurve(int);
	string reverse(string);
	void command(string);

};

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

	Turtle bob;




};
