#include "Point.h"
#include<iostream>

using namespace std;

void Point::setX(int iX) //input for x coordinate
{
	x = iX;
}

void Point::setY(int iY) //y coordinate
{
	y = iY;
}

bool Point::setCheck(int iCheck)
{
	if (iCheck == 1 || iCheck == 0 || iCheck == -1) { // 'O' - 'Null' - 'X'
		check = iCheck;
		return true;
	}
	return false;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

int Point::getCheck()
{
	return check;
}
