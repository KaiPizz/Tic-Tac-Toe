#pragma once
#include"Windows.h" //once you include those headers in header file, you dont need to include those again in cpp file (vice versa)

class Console
{
public:
	static void fixConsoleWindow();
	//fixed the console window
	static void gotoXY(int x, int y);
	//move to coordinates (x,y) in the console screen
	static void setConsoleWindow(int width, int height);
	//adjust the size of the console based on the size of width and height parameters
	
	Console();
	//constructor of the class
	~Console();
	//destructor of the class - invoked automatically when the object goes out of scope	
};

