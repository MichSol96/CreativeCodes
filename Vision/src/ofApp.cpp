#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	    vidGrabber.setVerbose(true);
	    vidGrabber.setup(1024, 768);
		


		colorImg.allocate(1024, 768);
		grayImage.allocate(1024, 768);
		grayBg.allocate(1024, 768);
		grayDiff.allocate(1024, 768);

		bLearnBakground = true;
		threshold = 50;

		ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

	bool bNewFrame = false;
	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();
   

		if (bNewFrame) {

            
			colorImg.setFromPixels(vidGrabber.getPixels());
            

			grayImage = colorImg;
			if (bLearnBakground == true) {
				grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
				bLearnBakground = false;
			}

			// take the abs value of the difference between background and incoming and then threshold:
			grayDiff.absDiff(grayBg, grayImage);
			grayDiff.threshold(threshold);

			// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
			// also, find holes is set to true so we will get interior contours as well....
			contourFinder.findContours(grayDiff, 20, (1024 * 768) / 3, 10, true);	// find 
		}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//grayDiff.draw(20, 20);

	// then draw the contours:

	ofFill();
	
	ofSetColor(ofColor::white);

	
	contourFinder.draw();

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		bLearnBakground = true;
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
