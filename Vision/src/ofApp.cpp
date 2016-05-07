#include "ofApp.h"
using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup(){

	    tracker.setup();
	    videoGrab.setup(1024, 768);

		colorImage.allocate(1024, 768);
		grayImage.allocate(1024, 768);
		grayBg.allocate(1024, 768);
		diff.allocate(1024, 768);

		learnBg = true;
		threshold = 50;

		ofBackground(0);

		eye1.load("eye1.jpg");
		eye2.load("eye2.JPG");
		eye1.resize(50, 50);
		eye2.resize(50, 50);

}

//--------------------------------------------------------------
void ofApp::update(){

	bool camFrame = false;
	videoGrab.update();
	camFrame = videoGrab.isFrameNew();
   

		if (camFrame) {
			tracker.update(toCv(videoGrab));
			colorImage.setFromPixels(videoGrab.getPixels());
         
			grayImage = colorImage;
			if (learnBg == true) {
				grayBg = grayImage;		
				learnBg = false;
			}

			diff.absDiff(grayBg, grayImage);
			diff.threshold(threshold);

			contours.findContours(diff, 0, (1024 * 768) / 3, 10, true);	// find 
		}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//diff.draw(0, 0);
	
	//draw the eyes in
	ofPolyline leftEye = tracker.getImageFeature(ofxFaceTracker::LEFT_EYE);
	eye1.draw(leftEye.getCentroid2D());
	ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
	eye2.draw(rightEye.getCentroid2D());

	ofSetLineWidth(2);
	// then draw the contours (outline):
	ofFill();
	ofSetColor(ofColor::white);
	contours.draw();


	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		learnBg = true;
		break;
	}
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
