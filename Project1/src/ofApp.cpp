#include "ofApp.h"
#include "stdlib.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	csv.load("4-18-16.csv");
	ofSetBackgroundColor(ofColor::black);
	ofSetLineWidth(3);
	
	len = 500;

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
void ofApp::update(){
	
	

	len *= 0.66;

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofTranslate(ofGetWidth() / 2, ofGetHeight());
	ofDrawLine(0, 0, 0, -len);
	ofTranslate(0, -len);

	//ofSetFrameRate(10);
	//ofTranslate(treeX, treeY);

	ofDrawLine(0, 0, 0, -len);
	ofTranslate(0, -len);

	//Each branch’s length shrinks by 2/3rds
	
		ofPushMatrix();
		ofRotate(thetha);
		ofDrawLine(0, 0, 0, -len);
		ofTranslate(0, -len);
		ofPopMatrix();

		ofPushMatrix();
		ofRotate(-(thetha));
		ofDrawLine(0, 0, 0, -len);
		ofTranslate(0, -len);
		ofPopMatrix();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
