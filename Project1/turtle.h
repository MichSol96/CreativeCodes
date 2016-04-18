#pragma once
#include<string>
using namespace std;

class Turtle {
	double myX;
	double myY;
	double myDirection;
	bool penDown;

public:
	void setValues(int, int, double);
	void moveForward();
	void moveBackward();
	void turnLeft(double);
	void turnRight(double);
	void setPen(bool);
	string dragonCurve(int);
	string reverse(string);
	void command(string);
};
