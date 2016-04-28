#include "ofApp.h"
#include "stdlib.h"

//--------------------------------------------------------------
void ofApp::setup() {


	ofHideCursor(); //ofShowCursor() -> unhide
	ofSetBackgroundAuto(false);

	csv.load("4-18-16.csv");
	ofSetBackgroundColor(ofColor::whiteSmoke);
	ofSetLineWidth(3);


}

//--------------------------------------------------------------
void ofApp::update() {

	//creates a random value between 0 and 255 for r, g and b
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	a = ofMap(ofGetMouseX(), 10, ofGetWidth(), 10, 255);//alpha based on mouse position

	//sets the color based on the current r, g, b value
	ofSetColor(r, g, b, a);

	int i = 0;
	//randNum = rand() % csv.getNumRows(); //get a random row from the csv file

	row = csv.getRow(i); // grab that random row 
	temp = row.getInt(i); //create temp based on randNum 
	thetha = (PI * temp) - (r * g + b * a);

	i++;


}

//--------------------------------------------------------------
void ofApp::draw() {

	
	for (int i = 10; i >= 0; i--) {
		
		ofSetFrameRate(2);
		recursiveTree(400);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::recursiveTree(float level) {//makes a recursive tree based on a number of branches
	treeX = ofGetMouseX();
	treeY = ofGetMouseY();


	//ofSetFrameRate(10);
	ofTranslate(treeX, treeY);
	branch(level);
}

void ofApp::branch(float len)//creates branches for the free based on the initial length passed in
{
	ofDrawLine(0, 0, 0, -len);
	ofTranslate(0, -len);

	//Each branch’s length shrinks by 2/3rds
	len *= 0.66;

	if (len > 2) {

		ofPushMatrix();
		ofRotate(thetha);
		branch(len);
		ofPopMatrix();

		ofPushMatrix();
		ofRotate(-(thetha));
		branch(len);
		ofPopMatrix();
	}



}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}