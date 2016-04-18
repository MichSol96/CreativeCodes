
#include<string>
#include <math.h>
#include "ofMain.h"
#include "turtle.h"

using namespace std;

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
			ofDrawLine(tempx, tempy, myX, myY);
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
			default: //do Nothing
			}
		}
	}
};

	
