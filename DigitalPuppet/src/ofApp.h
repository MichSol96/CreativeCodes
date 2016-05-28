#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCV.h"
#include "ofxFaceTracker.h"
#include "ofxFaceTrackerThreaded.h"
#include "ofxKinectV2OSC.h"
#define _USE_LIVE_VIDEO	
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	
	
	ofVideoGrabber videoGrab;
	
	ofxFaceTrackerThreaded tracker;

	//vectors of face images
	vector<string> leftEye;
	vector<string> rightEye;
	vector<string> leftEyebrow;
	vector<string> rightEyebrow;
	vector<string> mouth;
	vector<string> nose;

	//vectors of left side of the body images
	vector<string> leftArm;
	vector<string> leftLeg;

	vector<string> torso;

	//vector of right side of the body images
	vector<string> rightArm;
	vector<string> rightLeg;


	ofImage eye1;
	ofImage eye2;
	ofImage eyebrow1;
	ofImage eyebrow2;
	ofImage mouthClosed;
	ofImage nose1; 

	ofImage leg1;
	ofImage leg2;
	

	ofImage arm1;
	ofImage arm2;

	ofImage torso1;

	
	ofxKinectV2OSC kinect;
	Skeleton* skeleton;
	vector<Skeleton>* skeletons;
	ofTrueTypeFont smallFont;
	BodyRenderer renderer;

	
};
