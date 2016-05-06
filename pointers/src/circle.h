#pragma once
#include "ofMain.h"

class Circle {

public:
	Circle();
	void update();
	void draw();
	void explodeAt(int, int);
	float x, y, velX, velY, size;
	ofColor color;
	int bounces;

};
#pragma once
