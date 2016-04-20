#include "ofApp.h"
#include "stdlib.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
		
	ofSetBackgroundColor(ofColor::black);
	//ofSetBackgroundAuto(false);
	ofSetLineWidth(3);
	//ofSetColor(ofColor::mediumSeaGreen);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(-5);

	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;

	ofSetColor(r, g, b);

	thetha = rand() % (int)(40 * PI);

	treeX = rand() % ofGetWidth();
	treeY = rand() % ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (float i = 300; i > 0; i -= 5) {
		recursiveTree(i);
	}
		
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

void ofApp::recursiveTree(float level) {
	ofTranslate(treeX, treeY);
	branch(level);
}

void ofApp::branch(float len)
{
	
	

	ofDrawLine(0, 0, 0, -len);
	ofTranslate(0, -len);
	
	//Each branch’s length shrinks by 2/3rds
	len *= 0.66;
	
	if (len > 2) {
		
		ofPushMatrix();
		ofRotate( thetha);
		branch(len);
		ofPopMatrix();

		ofPushMatrix();
		ofRotate(-(thetha ));
		branch(len);
		ofPopMatrix();
	}
												   

	/*
	for (int y = 0; y< ofGetHeight() - 1; y++) {
		for (int x = 0; x < ofGetWidth() - 1; x++) {
			mesh.addIndex(x + y*ofGetWidth());               // 0
			mesh.addIndex((x + 1) + y*ofGetWidth());           // 1
			mesh.addIndex(x + (y + 1)*ofGetWidth());           // 10

			mesh.addIndex((x + 1) + y*ofGetWidth());           // 1
			mesh.addIndex((x + 1) + (y + 1)*ofGetWidth());       // 11
			mesh.addIndex(x + (y + 1)*ofGetWidth());           // 10
		}
	}
	*/	
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
