#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxFaceTracker.h"
#include "ofxFaceTrackerThreaded.h"
//#include "ofxKinectV2OSC.h"
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

	ofxCvColorImage	colorImage;

	ofxCvGrayscaleImage grayImage;
	ofxCvGrayscaleImage grayBg;
	ofxCvGrayscaleImage diff;
	ofxFaceTrackerThreaded tracker;
	ofxCvContourFinder contours;

	ofImage eye1;
	ofImage eye2;
	ofImage mouthOpen;
	ofImage mouthClosed;
	ofImage mouthSmile;
	ofImage nose;

	int threshold;
	bool learnBg;


	/*ofxKinectV2OSC kinect;
	Skeleton* skeleton;
	vector<Skeleton>* skeletons;
	ofTrueTypeFont smallFont;
	BodyRenderer renderer;*/
};
