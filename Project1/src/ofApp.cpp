#include "ofApp.h"
#include<thread>


//--------------------------------------------------------------
void ofApp::setup() {


	bob.setValues(0, 0, 30);



	bob.command(bob.dragonCurve(20));

}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	bob.getMesh().draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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

void Turtle::setValues(int x, int y, double dir) {
	myX = x;
	myY = y;
	myDirection = dir;
	penDown = true;



}

void Turtle::moveForward() {
	double tempx = myX;
	double tempy = myY;

	myX += cos(myDirection);
	myY += sin(myDirection);

	if (penDown) {
		//ofDrawLine(tempx, tempy, myX, myY);

		for (int y = 0; y < ofGetHeight(); y++) {
			for (int x = 0; x < ofGetWidth(); x++) {
				mesh.addVertex(ofPoint(getMyX(), getMyY(), 0)); // make a new vertex
				mesh.addColor(ofFloatColor(0, 0, 0));  // add a color at that vertex
			}
		}

		for (int y = 0; y< ofGetHeight() - 1; y++) {
			for (int x = 0; x< ofGetWidth() - 1; x++) {
				mesh.addIndex(x + y*ofGetWidth());               // 0
				mesh.addIndex((x + 1) + y*ofGetWidth());           // 1
				mesh.addIndex(x + (y + 1)*ofGetWidth());           // 10

				mesh.addIndex((x + 1) + y*ofGetWidth());           // 1
				mesh.addIndex((x + 1) + (y + 1)*ofGetWidth());       // 11
				mesh.addIndex(x + (y + 1)*ofGetWidth());           // 10
			}
		}
	}

}

void Turtle::moveBackward() {
	double tempx = myX;
	double tempy = myY;

	myX -= cos(myDirection);
	myY -= sin(myDirection);

	if (penDown) {
		ofDrawLine(tempx, tempy, myX, myY);

	}
}

void Turtle::turnLeft(double angle) {
	myDirection += angle;
	if (myDirection < 0.0) {
		myDirection += 2.0 * PI;
	}
	if (myDirection > 2.0) {
		myDirection -= 2.0 * PI;
	}
}

void Turtle::turnRight(double angle) {
	myDirection -= angle;
	if (myDirection < 0) {
		myDirection += 2 * PI;

	}
	if (myDirection > 2.0) {
		myDirection -= 2.0 * PI;
	}
}

void Turtle::setPen(bool value) {
	penDown = value;
}

string Turtle::dragonCurve(int level) {
	if (level == 0) {
		return "FRF";
	}
	else {
		string temp = dragonCurve(level - 1);
		return temp + "R" + reverse(temp);
	}
}

string Turtle::reverse(string aString) {
	string result = "";
	for (int i = aString.length() - 1; i >= 0; i--) {

		switch (aString.at(i)) {

		case 'L': result += 'R';
			break;
		case 'R': result += 'L';
			break;
		default: result += aString.at(i);
		}
	}
	return result;
}

void Turtle::command(string program) {

	for (int i = 0; i < program.length(); i++) {
		switch (program.at(i)) {
		case 'F': moveForward();
			break;
		case 'B': moveBackward();
			break;
		case 'L': turnLeft(PI / 2);
			break;
		case 'R': turnRight(PI / 2);
			break;
		case 'U': setPen(false);
			break;
		case 'D': setPen(true);
			break;
		default:
			break;//do Nothing
		}
	}
}

double Turtle::getMyDir() {
	return myDirection;
}

double Turtle::getMyX() {
	return myX;
}

double Turtle::getMyY() {
	return myY;
}

ofMesh Turtle::getMesh() {
	return mesh;
}
