#include "ofApp.h"
using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup() {
	
	leftEye.push_back("LeftEye1.png");
	leftEye.push_back("LeftEye2.png");
	leftEye.push_back("LeftEye3.png");

	rightEye.push_back("RightEye1.png");
	rightEye.push_back("RightEye2.png");
	rightEye.push_back("RightEye3.png");

	leftEyebrow.push_back("LeftEyebrow1.png");
	leftEyebrow.push_back("LeftEyebrow2.png");
	leftEyebrow.push_back("LeftEyebrow3.png");

	rightEyebrow.push_back("RightEyebrow1.png");
	rightEyebrow.push_back("RightEyebrow2.png");
	rightEyebrow.push_back("RightEyebrow3.png");

	mouth.push_back("mouth1.png");
	mouth.push_back("mouth2.png");
	mouth.push_back("mouth3.png");

	nose.push_back("nose1.png");
	nose.push_back("nose2.png");
	nose.push_back("nose3.png");

	leftLeg.push_back("LeftLeg1.png");
	leftLeg.push_back("LeftLeg2.png");
	leftLeg.push_back("LeftLeg3.png");

	rightLeg.push_back("RightLeg1.png");
	rightLeg.push_back("RightLeg2.png");
	rightLeg.push_back("RightLeg3.png");

	leftArm.push_back("LeftArm1.png");
	leftArm.push_back("LeftArm2.png");
	leftArm.push_back("LeftArm3.png");

	rightArm.push_back("RightArm1.png");
	rightArm.push_back("RightArm2.png");
	rightArm.push_back("RightArm3.png");

	torso.push_back("torso1.png");
	torso.push_back("torso2.png");
	torso.push_back("torso3.png");


	videoGrab.listDevices();
	videoGrab.setDeviceID(0);
	
	smallFont.loadFont("STONIN_.TTF", 16);
	kinect.setup(12345, smallFont);

	//Here we get a pointer to the list of skeletons it has parsed
	//from OSC
	skeletons = kinect.getSkeletons();

	//We could inspect the skeletons and draw them here in ofApp
	//but for now let's pass the list to a default renderer class
	renderer.setup(skeletons);

	tracker.setup();

	videoGrab.setup(1024, 768);
	videoGrab.getPixels().mirror(false, true);


	ofBackground(0);

	
	eye1.load(leftEye.at(ofRandom(3)));
	eye2.load(rightEye.at(ofRandom(3)));

	mouthClosed.load(mouth.at(ofRandom(3)));
	nose1.load(nose.at(ofRandom(3)));
	

	eyebrow1.load(leftEyebrow.at(ofRandom(3)));
	eyebrow2.load(rightEyebrow.at(ofRandom(3)));

	leg1.load(leftLeg.at(ofRandom(3)));
	leg2.load(rightLeg.at(ofRandom(3)));
	

	arm1.load(leftArm.at(ofRandom(3)));
	arm2.load(rightArm.at(ofRandom(3)));
	

	torso1.load(torso.at(ofRandom(3)));
	
	

}

//--------------------------------------------------------------
void ofApp::update() {

	kinect.update();

	bool camFrame = false;
	
	videoGrab.update();
	videoGrab.getPixels().mirror(false, true);
	camFrame = videoGrab.isFrameNew();

	
	if (camFrame) {
		tracker.update(toCv(videoGrab));
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	kinect.drawDebug();

	//We passed the skeleton list pointer to the renderer earlier,
	//now we tell it to draw them
	//renderer.draw();

	
	
	for(int i = 0; i < skeletons->size(); i++) {
	//ofSetColor(ofColor::fromHsb(ofGetFrameNum() % 255, 255, 255));
		Joint leftHip = skeletons->at(i).getHipLeft();
		Joint rightHip = skeletons->at(i).getHipRight();
		
		Joint leftShoulder = skeletons->at(i).getShoulderLeft();
		Joint rightShoulder = skeletons->at(i).getShoulderRight();

		Joint torso = skeletons->at(i).getSpineShoulder();

		
		ofLog() << "range of z: " << leftHip.z();
		
		if (leftHip.z() >= 12) {
			//everything get comically small when you stand far enough back
			
			leg1.draw(leftHip.x() - 40, leftHip.y(), 5 * leftHip.z(), 25 * leftHip.z());
			leg2.draw(rightHip.x(), rightHip.y(), 5 * rightHip.z(), 25 * rightHip.z());
			
			arm1.draw(leftShoulder.x() - 40, leftShoulder.y(), 5 * leftShoulder.z(), 15 * leftShoulder.z()); //good placement and scaling
			arm2.draw(rightShoulder.x(), rightShoulder.y(), 5 * rightShoulder.z(), 15 * rightShoulder.z()); //need to cut arms at elbows to get a full range of motion

			torso1.draw(torso.x() - 60, torso.y(), 11 * torso.z(), 15 * torso.z());//good scaling*/
		}
		else {
			leg1.draw(leftHip.x() - 40, leftHip.y(), 25 * leftHip.z(), 125 * leftHip.z());
			leg2.draw(rightHip.x(), rightHip.y(), 25 * rightHip.z(), 125 * rightHip.z());
			

			arm1.draw(leftShoulder.x() - 40, leftShoulder.y(), 25 * leftShoulder.z(), 75 * leftShoulder.z()); //good placement and scaling
			arm2.draw(rightShoulder.x(), rightShoulder.y(), 25 * rightShoulder.z(), 75 * rightShoulder.z()); //need to cut arms at elbows to get a full range of motion

			torso1.draw(torso.x() - 60, torso.y(), 50 * torso.z(), 75 * torso.z());//good scaling*/
		}
		
	}
	

	//tracker.draw();
	//draw the face in


	ofPolyline leftEye = tracker.getImageFeature(ofxFaceTrackerThreaded::LEFT_EYE);
	ofPolyline rightEye = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYE);
	ofPolyline leftEyebrow = tracker.getImageFeature(ofxFaceTrackerThreaded::LEFT_EYEBROW);
	ofPolyline rightEyebrow = tracker.getImageFeature(ofxFaceTracker::RIGHT_EYEBROW);
	ofPolyline mouth = tracker.getImageFeature(ofxFaceTrackerThreaded::OUTER_MOUTH);
	ofPolyline nosePos = tracker.getImageFeature(ofxFaceTrackerThreaded::NOSE_BASE);

	eye1.draw(leftEye.getBoundingBox().getX(), leftEye.getBoundingBox().getY(), 5 * tracker.getScale(), 5 * tracker.getScale());
	eye2.draw(rightEye.getBoundingBox().getX(), rightEye.getBoundingBox().getY(), 5 * tracker.getScale(), 5 * tracker.getScale());
	eyebrow1.draw(leftEyebrow.getBoundingBox().getX(), leftEyebrow.getBoundingBox().getY(), 5 * tracker.getScale(), 5 * tracker.getScale());
	eyebrow2.draw(rightEyebrow.getBoundingBox().getX(), rightEyebrow.getBoundingBox().getY(), 5 * tracker.getScale(), 5 * tracker.getScale());
	mouthClosed.draw(mouth.getBoundingBox().getX() + 15, mouth.getBoundingBox().getY(), 15 * tracker.getScale(), 8 * tracker.getScale());
	nose1.draw(nosePos.getBoundingBox().getX(), nosePos.getBoundingBox().getY() - 40,  5 * tracker.getScale(), 8 * tracker.getScale());
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	ofSetColor(255);
	if (key == 'd') 
		kinect.toggleDebug();
	if (key == ' ') {
		eye1.load(leftEye.at(ofRandom(3)));
		eye2.load(rightEye.at(ofRandom(3)));

		mouthClosed.load(mouth.at(ofRandom(3)));
		nose1.load(nose.at(ofRandom(3)));

		eyebrow1.load(leftEyebrow.at(ofRandom(3)));
		eyebrow2.load(rightEyebrow.at(ofRandom(3)));

		leg1.load(leftLeg.at(ofRandom(3)));
		leg2.load(rightLeg.at(ofRandom(3)));


		arm1.load(leftArm.at(ofRandom(3)));
		arm2.load(rightArm.at(ofRandom(3)));


		torso1.load(torso.at(ofRandom(3)));
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
