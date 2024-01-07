#pragma once
#include"conio.h" //Console input/output
#include"Console.h"

class Point
{
private: //by default, class is private
	int x{};
	int y{};
	//x and y coordinates on the board
	int check{};
	//identified cells on the board: 'O' = 1, 'X' = -1, 'NULL'(empty) = 0

public:
	void setX(int); //set the value of 'X' variable
	void setY(int); //set the value of 'Y' variable
	bool setCheck(int); //set the value of 'check' variable

	int getX(); //return value of 'x'
	int getY(); //return value of 'y'
	int getCheck(); //return value of 'check'
};

