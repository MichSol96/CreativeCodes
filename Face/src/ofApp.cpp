#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//Stem
	ofSetColor(29, 161, 29);
	ofDrawRectangle(450, 25, 100, 100);

	//Pumpkin Body
	ofSetColor(245, 165, 17);
	ofSetCircleResolution(50);
	ofDrawCircle(350, 350, 300);
	ofDrawCircle(650, 350, 300);
	ofDrawRectRounded(300, 550, 310, 97, 10);

	//Nose
	ofSetColor(255, 208, 0);
	ofDrawTriangle(500, 340, 400, 430, 600, 430);

	//Right Eye
	ofDrawBezier(570, 300, 800, 85, 790, 300, 750, 300);

	//Left Eye
	ofSetColor(255, 208, 0);
	ofPushMatrix();
	ofRotate(50, 0.5, 0.75, 0);
	ofDrawEllipse(293, 230, 225, 100);
	ofPopMatrix();

	//Mouth
	ofDrawCurve(480, 20, 280, 500, 720, 500, 620, 20);

	//Teeth
	ofSetColor(245, 165, 17);
	ofDrawRectangle(440, 500, 50, 25);
	ofDrawRectangle(510, 500, 50, 25);

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
