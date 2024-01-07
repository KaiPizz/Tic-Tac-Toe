#pragma once
#include"Console.h"
#include"Point.h"

//2 arrays of defense & attack points for hard mode
const long defenseScore1[7] = {0, 8, 512, 32012, 2024115, 233059637};
const long attackScore1[7] = { 0, 64, 4096, 256096, 16192920, 1864477096 };

//2 arrays of defense & attack points for easy mode
const long defenseScore2[7] = {1,2,3,5,3,2};
const long attackScore2[7] = {1,2,3,4,5,6};

class board
{
private:
	int size{}; 
	//size of the board

	int left{}; 
	int top{};
	//coordinates of the left & top of the board

	Point** pArr;
	//2-dimensional array to convert (x,y) coordinates to cells in a 2D
	//'pArr' is used to dynamically allocate memory for a 2-dimensional array of 'Point' object, representing the board .
public:
	int getSize();
	int getLeft();
	int getTop();
	
	int getXAt(int, int);
	int getYAt(int, int);
	//get the coordinates of x & y at position i, j on the 2-dimensional array board pArr

	int checkXON(int i, int j) {
		return pArr[i][j].getCheck(); //getCheck function in Point class
	}
	//get the 'check' variable from Point class. See if its 'X', 'O' or 'Null'

	void loadData(int, int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int checkWin(int, int);

	Point searchHardMove();
	Point searchEasyMove();
	//computer move

	long horizontalDefensePoint(long, long, const long defenseScore[], const long attackScore[]);
	long verticalDefensePoint(long, long, const long defenseScore[], const long attackScore[]);
	long diagonalDefensePoint1(long, long, const long defenseScore[], const long attackScore[]);
	long diagonalDefensePoint2(long, long, const long defenseScore[], const long attackScore[]);

	long horizontalAttackPoint(long, long, const long defenseScore[], const long attackScore[]);
	long verticalAttackPoint(long, long, const long defenseScore[], const long attackScore[]);
	long diagonalAttackPoint1(long, long, const long defenseScore[], const long attackScore[]);
	long diagonalAttackPoint2(long, long, const long defenseScore[], const long attackScore[]);
	//browse empty cells and calculate points for each cell horizontally, vertically, diagonally forwards and diagonally backwards. 
	
	int checkWinRow(int x, int y, int value); //value (1 or -1) /  'O' or 'X', check win by row
	int checkWinCol(int x, int y, int value); //check win by column
	int checkWinDiag1(int x, int y, int value); //check win by forward diagonal
	int checkWinDiag2(int x, int y, int value); //check win by backward diagonal

	int countO; //count the number of 'X' on the board
	int countX; //count the number of 'O' on the board

	board();
	board(int pSize, int pX, int pY);
	~board();
};