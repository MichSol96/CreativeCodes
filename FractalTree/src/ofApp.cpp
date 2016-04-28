#include "ofApp.h"
#include "stdlib.h"

//--------------------------------------------------------------
void ofApp::setup() {


	csv.load("4-18-16.csv");
	ofSetBackgroundColor(ofColor::black);
	ofSetLineWidth(3);


}

//--------------------------------------------------------------
void ofApp::update() {

	//creates a random value between 0 and 255 for r, g and b
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;

	//sets the color based on the current r, g, b value
	ofSetColor(r, g, b);

	randNum = rand() % csv.getNumRows(); //get a random row from the csv file

	ofxCsvRow& row = csv.getRow(randNum); // grab that random row 
	temp = row.getInt(randNum); //create temp based on randNum 
	thetha = (temp * PI) - (r * g + b);




}

//--------------------------------------------------------------
void ofApp::draw() {
	for (float i = 300; i > 0; i -= 5) { //draws a recursive tree 60 with 60 branches
		recursiveTree(i);
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
	treeX = rand() % ofGetWidth();
	treeY = rand() % ofGetHeight();

	ofSetFrameRate(10);
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