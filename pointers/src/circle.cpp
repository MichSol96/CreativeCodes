#include "ofMain.h"

#include "circle.h"

Circle::Circle()
{
	x = ofRandom(ofGetWidth());
	y = ofRandom(ofGetHeight());

	velX = ofRandom(-4, 4);
	velY = ofRandom(-4, 4);
	color = ofColor(ofRandom(100, 200));

	size = ofRandom(10, 50);
}

void Circle::update() {
	x += velX;
	y += velY;

	if ((x < size)) {
		velX = -velX;
		x = size;
		bounces++;
	}
	if (x > ofGetWidth() - size) {
		velX = -velX;
		x = ofGetWidth() - size;
		bounces++;
	}
	if ((y < size)) {
		velY = -velY;
		y = size;
		bounces++;
	}
	if (y > ofGetHeight() - size) {
		velY = -velY;
		y = ofGetHeight() - size;
		bounces++;
	}
}

void Circle::draw() {
	ofFill();
	ofSetColor(color);
	ofCircle(x, y, size);
}

void Circle::explodeAt(int newX, int newY)
{
	x = newX;
	y = newY;

	velX = ofRandom(-4, 4);
	velY = ofRandom(-4, 4);
}


