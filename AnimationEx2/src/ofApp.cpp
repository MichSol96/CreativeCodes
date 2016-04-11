#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(ofColor::thistle);
	eX = ofGetWidth() / 2;
	eY = ofGetHeight() / 2;

	easing = 0.1;

}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetCircleResolution(25);
	ofSetColor(ofColor::darkOliveGreen);
	ofDrawCircle(eX, eY, 45);


	ofSetColor(ofColor::white);
	//left eye
	ofDrawCircle(eX - 20, eY - 15, 13);
	
	//right eye
	ofDrawCircle(eX + 20, eY - 15, 13);

	//pupils
	ofSetColor(ofColor::black);
	ofDrawCircle(eX - 15, eY - 12, 4);
	ofDrawCircle(eX + 15, eY - 12, 4);

	//mouth
	ofSetLineWidth(2);
	ofDrawLine(eX - 25, eY + 15, eX + 25, eY + 15);
	ofSetColor(ofColor::lightPink);
	ofDrawBezier(eX + 5, eY + 15, eX + 13, eY + 30, eX + 13, eY + 30, eX + 24, eY + 15);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_UP) {
		//move circle up
		eY -= 10;
	}
	else if (key == OF_KEY_DOWN) {
		eY += 10;
	}
	else if (key == OF_KEY_LEFT) {
		eX -= 10;
	}
	else if (key == OF_KEY_RIGHT) {
		eX += 10;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	//update the easing object
	eX += (ofGetMouseX() - eX) * easing;
	eY += (ofGetMouseY() - eY) * easing;
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
