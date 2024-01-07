#pragma once
#include"Point.h"
#include"Console.h"
#include"board.h"
#include"Game.h"

//some Basic color
#define SIZE			16   // BOARD SIZE

#define Black			0
#define Blue			1
#define Green			2
#define Aqua			3
#define Red				4
#define Purple			5
#define Yellow			6
#define White			7
#define Gray			8
#define LightGreen		10 //A
#define LightAqua		11 //B - Cyan
#define LightRed		12 //C
#define Pink			13 //D - Light purple
#define LightYellow		14 //E
#define BrightWhite		15 //F
#define defaultColor	7

struct point {
	int score1;
	int score2;
};

int Mode(char a[30]); //game modes
//void readNameFile(); // read the saved files
void print1();
void print2();
void print3();
void screen();

void textColor(int); //characters change color
void hideMouse();
void showMouse();
void mainMenu(int); //main menu
void printScoreBoard(); 

int playerVsCom(point& a, int, char data[30]); //hard bot
int playerVsCom2(point& a, int, char data[30]); //easy bot
int PvP(point& a, int, char data[30]);

void Tutorial();
void about();


