#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	gui.add(replusionForce.setup("Replusion Force", 11, 1, 20));
	gui.add(attractionForce.setup("Attraction Force", 6, 1, 20));

	ofBackground(ofColor::darkSlateGray);
	
	
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(60);

	
	for (int i = 0; i < 100; i++) {
		float w = ofRandom(20, 60);
		float h = ofRandom(20, 60);
		shared_ptr<ofxBox2dRect> rect = shared_ptr<ofxBox2dRect>(new ofxBox2dRect);
		rect.get()->setPhysics(5, .75, 1.2);
		rect.get()->setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, w, h);
		square.push_back(rect);
	}
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	box2d.update();
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	float minDis = ofGetMousePressed() ? 300 : 200;

	for (int i = 0; i < square.size(); i++) {

		float dis = mouse.distance(square[i].get()->getPosition());
		if (dis < minDis) square[i].get()->addRepulsionForce(mouse, replusionForce);
		else square[i].get()->addAttractionPoint(mouse, attractionForce);

	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < square.size(); i++) {
		ofFill();
		ofSetColor(ofColor::darkSalmon);
		square[i].get()->draw();
	}

	// draw the ground
	box2d.drawGround();

	gui.draw();
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
