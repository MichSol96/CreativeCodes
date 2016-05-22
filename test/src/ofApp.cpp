#include "ofApp.h"
using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup() {
	/*
	smallFont.loadFont("STONIN_.TTF", 16);
	kinect.setup(12345, smallFont);

	//Here we get a pointer to the list of skeletons it has parsed
	//from OSC
	skeletons = kinect.getSkeletons();

	//We could inspect the skeletons and draw them here in ofApp
	//but for now let's pass the list to a default renderer class
	renderer.setup(skeletons);*/

	tracker.setup();
	videoGrab.setup(1024, 768);

	colorImage.allocate(1024, 768);
	grayImage.allocate(1024, 768);
	grayBg.allocate(1024, 768);
	diff.allocate(1024, 768);

	learnBg = true;
	threshold = 50;

	ofBackground(0);

	eye1.load("eye1.png");
	eye2.load("eye2.png");
	mouthClosed.load("mouth-closed.png");
	nose.load("nose.png");

	//eye1.resize(50, 50);
	//eye2.resize(50, 50);
	//mouthClosed.resize(70, 70);
	//mouthOpen.resize(50, 50);
	//mouthSmile.resize(50, 50);
	//nose.resize(70, 70);

}

//--------------------------------------------------------------
void ofApp::update() {

	//kinect.update();

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
void ofApp::draw() {

	//kinect.drawDebug();

	//We passed the skeleton list pointer to the renderer earlier,
	//now we tell it to draw them
	//renderer.draw();

	//diff.draw(0, 0);
	tracker.draw();

	//draw the eyes in

	ofPolyline leftEye = tracker.getImageFeature(ofxFaceTrackerThreaded::LEFT_EYE);
	ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
	ofPolyline mouth = tracker.getImageFeature(ofxFaceTrackerThreaded::OUTER_MOUTH);
	ofPolyline nosePos = tracker.getImageFeature(ofxFaceTrackerThreaded::NOSE_BASE);

	eye1.draw(leftEye.getBoundingBox().getX(), leftEye.getBoundingBox().getY(), 5 * tracker.getScale(), 5 * tracker.getScale());

	eye2.draw(rightEye.getBoundingBox().getX(), rightEye.getBoundingBox().getY(), 5 * tracker.getScale(), 5 * tracker.getScale());

	mouthClosed.draw(mouth.getBoundingBox().getX() + 15, mouth.getBoundingBox().getY(), 10 * tracker.getScale(), 8 * tracker.getScale());

	nose.draw(nosePos.getBoundingBox().getX(), nosePos.getBoundingBox().getY() - 60, 5 * tracker.getScale(), 8 * tracker.getScale());



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case ' ':
		learnBg = true;
		break;
	}
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
