#include "ofApp.h"
#include "circle.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofSetCircleResolution(50);
	ofBackground(100);

	for (int i = 0; i < 20; i++) {
		Circle *c = new Circle();
		circles.push_back(c);
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	vector<Circle*>::iterator iter;
	for (iter = circles.begin(); iter != circles.end(); ) {
		Circle *c = *(iter);
		if (c->bounces > 4) {
			delete c;
		}
		else {
			c->update();
			iter++;
		}
		
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (Circle *c : circles) {
		c->draw();
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
	for (Circle *c : circles) {
		c->explodeAt(ofGetMouseX(), ofGetMouseY());
	}
	Circle *c = new Circle();

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
