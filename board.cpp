#include "board.h"
#include"Play.h"
#include<stdio.h>
#include <iostream>
#include<vector>

using namespace std;

vector<Point> win;
//declared a vector named 'win' thats hold the objects of the Point class

int board::getSize()
{
	return size;
}

int board::getLeft()
{
	return left;
}

int board::getTop()
{
	return top;
}

int board::getXAt(int i, int j)
{
	return pArr[i][j].getX();
}

int board::getYAt(int i, int j)
{
	return pArr[i][j].getY();
}

//const int Win{ 5 };
//bool board::checkWin(char playerSymbol) const
//{
//	//check horizontal win	
//	for (int i{ 0 }; i < SIZE; i++) {
//		int count = 0;
//		for (int j{ 0 }; j < SIZE; j++) {
//			if (grid[i][j] == playerSymbol)
//				count++;
//		}
//		if (count == Win)
//			return true;
//	}
//
//	//check vertical win
//	for (int j{ 0 }; j < SIZE; j++) {
//		int count = 0;
//		for (int i{ 0 }; i < SIZE; i++) {
//			if (grid[i][j] == playerSymbol)
//				count++;
//		}
//		if (count == Win)
//			return true;
//	}
//
//	//check diagonal win (top-left to bottom-right)
//	for (int i{ 0 }; i < SIZE-4; i++) { //minus 4 bc later we plus n(up to 4, n < 5) in the grid 
//		int tlrb = 0;
//		for (int j{ 0 }; j < SIZE-4; j++) {
//			for (int n{ 0 }; n < 5; n++) {
//				if (grid[i + n][j + n] == playerSymbol)
//					tlrb++;
//			}
//			if (tlrb == Win)
//				return true;
//			else
//				tlrb = 0; //reset the count for next iteration 
//		}
//	}
//
//	//check diagonal win (bottom-left to top-right)
//	for (int i{ 0 }; i < SIZE; i++) {
//		int bltr = 0;
//		for (int j{ 0 }; j < SIZE; j++) {
//			for (int n{ 0 }; n < 5; n++) {
//				if (grid[i + n][j + n] == playerSymbol)
//					bltr++;
//			}
//			if (bltr == Win)
//				return true;
//			else
//				bltr = 0;
//		}
//	}
//}

void board::loadData(int i, int j, int k) // position on the board(i,j) and 'k' represent its symbol ('O','X','Null') as ('1', '-1', '0')
{
	if (size == 0) 
		return;

	pArr[i][j].setX(4 * j + left + 2); //'4*j' scaling the x coordinate based on the column index 'j'. 'left' left coordinate of the game board of the console screen. '2' an offset to adjust the x coordinate 
									  //the expression is calculating the x-coordinate of the point in terms of console screen coordinates, considering the block width, the left coordinate of the board, and an offset. 
	pArr[i][j].setY(2 * i + top + 1);  //same
	pArr[i][j].setCheck(k); //set the check value of the point at position(i,j) on the game board.
	
	if (k == -1) {
		textColor(Red); //X
		Console::gotoXY(4 * j + left + 2, 2 * i + top + 1);
		cout << "X";
		countX++;
	}

	if (k == 1) {
		textColor(Blue); //O
		Console::gotoXY(4 * j + left + 2, 2 * i + top + 1);
		cout << "O";
		countO++;
	}
}

void board::resetData()
{
	if (size == 0) 
		return;

	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			pArr[i][j].setX(4 * j + left + 2);
			pArr[i][j].setY(2 * i + top + 1);
			pArr[i][j].setCheck(0); //assign value 0(Null)
		}
	}
}

void board::drawBoard()
{
	if (size == 0)
		return;

	textColor(defaultColor);
	//draw right vertical borders
	for (int i{ 0 }; i < SIZE * 2; i++) { //SIZE*2 created a visual representation where each row consists of 2 lines: one for the cell and other for the separator between cells.
		Sleep(1); //delay function, 1 = one millisecond between each step of drawing process, used to create visual effect of the board is drawn gradually.
		Console::gotoXY(SIZE * 4, i + 1); //x coordinate = SIZE*4 and y coordinate = i+1
		if ((i + 1) % 2 == 1)
			cout << char(186); //'||'
		else
			cout << char(182); //https://genuinecoder.com/ascii-code-for-characters-in-c-program-html/
	}

	//draw horizontal lines
	for (int i{ 0 }; i < SIZE*2; i+=2) {
		Sleep(1);
		Console::gotoXY(0, i);
		for (int j{ 0 }; j < SIZE * 4; j++) {
			if (j % 4 == 0)
				cout << char(197); //looks like a intersection, used to draw connection points.
			else
				cout << char(196); 
		}
	}

	//draw left vertical borders
	for (int i{ 0 }; i < SIZE * 2; i++) {
		Sleep(1);
		Console::gotoXY(0, i + 1);
		if ((i + 1) % 2 == 1)
			cout << char(186);
		else
			cout << char(199);
	}

	//draw vertical lines
	for (int i{ 1 }; i < SIZE * 2; i+=2) {
		for (int j{ 0 }; j < SIZE * 4; j += 4) {
			Sleep(1);
			Console::gotoXY(j, i);
			if (j == 0)
				continue;
			cout << char(179);
		}
	}

	//draw top row borders
	Console::gotoXY(0, 0);
	for (int i{ 0 }; i < SIZE * 4; i++) {
		Sleep(1);
		if (i % 4 == 0)
			cout << char(209);
		else
			cout << char(205);
	}
	Console::gotoXY(0, 0);
	cout << char(201);
	Console::gotoXY(SIZE * 4, 0);
	cout << char(187);

	//draw bottom row borders
	Console::gotoXY(0, SIZE * 2);
	for (int i{ 0 }; i < SIZE * 4; i++) {
		Sleep(1);
		if (i % 4 == 0)
			cout << char(207);
		else
			cout << char(205);
	}
	Console::gotoXY(0, SIZE * 2);
	cout << char(200);
	Console::gotoXY(SIZE * 4, SIZE * 2);
	cout << char(188);

	//setting Cursor position
	Console::gotoXY(pArr[0][0].getX(), pArr[0][0].getY());
}

int board::checkBoard(int pX, int pY, bool pTurn)
{
	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			if (pArr[i][j].getX() == pX && pArr[i][j].getY() == pY && pArr[i][j].getCheck() == 0) {
				if (pTurn) {
					pArr[i][j].setCheck(-1);
					countX++;
				}
				else {
					pArr[i][j].setCheck(1);
					countO++;
				}
				return pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}

int board::checkWin(int x, int y)
{
	//X win, X = '-1'
	if (checkWinRow(x, y, -1) == 1)
		return -1;
	if (checkWinCol(x, y, -1) == 1)
		return -1;
	if (checkWinDiag1(x, y, -1) == 1)
		return -1;
	if (checkWinDiag2(x, y, -1) == 1)
		return -1;

	//O win
	if (checkWinRow(x, y, 1) == 1)
		return 1;
	if (checkWinCol(x, y, 1) == 1)
		return 1;
	if (checkWinDiag1(x, y, 1) == 1)
		return 1;
	if (checkWinDiag2(x, y, 1) == 1)
		return 1;

	//used to check if the board is full and there is no winner, it returns 0, indicating a draw.
	if (countX + countO == SIZE * SIZE)
		return 0; //draw

	//if the game is still ongoing
	return 2;
}

Point board::searchHardMove()
{
	Point move;

	int row{ 0 };
	int col{ 0 };
	//keep track to the row & column of the selected move

	long point{ 0 }; //keep track to the score of the selected move

	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			long attackPoint{ 0 };
			long defensePoint{ 0 };

			if (pArr[i][j].getCheck() == 0) {
				defensePoint += horizontalDefensePoint(i, j, defenseScore1, attackScore1);
				defensePoint += verticalDefensePoint(i, j, defenseScore1, attackScore1);
				defensePoint += diagonalDefensePoint1(i, j, defenseScore1, attackScore1);
				defensePoint += diagonalDefensePoint2(i, j, defenseScore1, attackScore1);

				attackPoint += horizontalAttackPoint(i, j, defenseScore1, attackScore1);
				attackPoint += verticalAttackPoint(i, j, defenseScore1, attackScore1);
				attackPoint += diagonalAttackPoint1(i, j, defenseScore1, attackScore1);
				attackPoint += diagonalAttackPoint2(i, j, defenseScore1, attackScore1);

				if (attackPoint > defensePoint) {
					if (point < attackPoint) {
						row = i;
						col = j;
						point = attackPoint;
					}
				}
				else { // defense point > attack point
					if (point < defensePoint) {
						row = i;
						col = j;
						point = defensePoint;
					}
				}
			}
		}
	}
	move.setX(col * 4 + 2);
	//This calculates the X coordinate based on the column index 'col'.
	//It multiplies the column index by 4 (since each column occupies 4 characters) and adds 2 to account for the layout.
	move.setY(row * 2 + 1); //same

	return move;
}

Point board::searchEasyMove()
{
	Point move;

	int row{ 0 };
	int col{ 0 };
	//keep track to the row & column of the selected move

	long point{ 0 }; //keep track to the score of the selected move

	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			long attackPoint{ 0 };
			long defensePoint{ 0 };

			if (pArr[i][j].getCheck() == 0) {

				defensePoint += horizontalDefensePoint(i, j, defenseScore2, attackScore2);
				defensePoint += verticalDefensePoint(i, j, defenseScore2, attackScore2);
				defensePoint += diagonalDefensePoint1(i, j, defenseScore2, attackScore2);
				defensePoint += diagonalDefensePoint2(i, j, defenseScore2, attackScore2);

				attackPoint += horizontalAttackPoint(i, j, defenseScore2, attackScore2);
				attackPoint += verticalAttackPoint(i, j, defenseScore2, attackScore2);
				attackPoint += diagonalAttackPoint1(i, j, defenseScore2, attackScore2);
				attackPoint += diagonalAttackPoint2(i, j, defenseScore2, attackScore2);

				if (attackPoint > defensePoint) {
					if (point < attackPoint) {
						row = i;
						col = j;
						point = attackPoint;
					}
				}
				else { // defense point > attack point
					if (point < defensePoint) {
						row = i;
						col = j;
						point = defensePoint;
					}
				}
			}
		}
	}
	move.setX(col * 4 + 2);
	//This calculates the X coordinate based on the column index 'col'.
	//It multiplies the column index by 4 (since each column occupies 4 characters) and adds 2 to account for the layout.
	move.setY(row * 2 + 1); //same

	return move;
}

long board::horizontalDefensePoint(long row, long col, const long defenseScore[], const long attackScore[])
{
	long scoreHorizontal = 0;
	int myPieces = 0;
	int enemyPieces = 0;
	int myPieces2 = 0;
	int enemyPieces2 = 0;

	//check tokens/pieces to the right of the current position
	for (int count{ 1 }; count < 6 && count + col < size; count++) {
		if (pArr[row][count + col].getCheck() == 1)
			myPieces++;
			//break;
		if (pArr[row][count + col].getCheck() == -1) {
			enemyPieces++;
			break;
		}
		if (pArr[row][count + col].getCheck() == 0) { //if there is no pieces its keep moving to the next position (to the right)
			//this 'for' block of code is counting the number of consecutive player tokens 'myPieces' to the right of the current position and the number of consecutive opponent tokens (enemyPieces) 
			//until either the end of the board or an empty position is encountered.
			for (int count2{ 2 }; count2 < 7 && count2 + col < size; count2++) {
				if (pArr[row][count2 + col].getCheck() == 1)
					myPieces2++;
				if (pArr[row][count + col].getCheck() == -1) {
					enemyPieces2++;
					break;
				}
				if (pArr[row][count2 + col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//check tokens to the left of the current position
	for (int count{ 1 }; count < 6 && col - count >= 0; count++) {
		if (pArr[row][col - count].getCheck() == 1) {
			myPieces++;
			break;
		}
		if (pArr[row][col - count].getCheck() == -1) {
			enemyPieces++;
			break;
		}
		if (pArr[row][col - count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && col - count2 >= 0; count2++) {
				if (pArr[row][col - count2].getCheck() == 1) {
					myPieces2++;
					break;
				}
				if (pArr[row][col - count2].getCheck() == -1) {
					enemyPieces2++;
					break;
				}
				if (pArr[row][col - count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myPieces == 2)
		return 0;
	if (myPieces == 0)
		scoreHorizontal += defenseScore[enemyPieces] * 2;
	else
		scoreHorizontal += defenseScore[enemyPieces];

	if (enemyPieces >= enemyPieces2)
		scoreHorizontal -= 1;
	else
		scoreHorizontal -= 2;

	if (enemyPieces == 4)
		scoreHorizontal *= 2;

	return scoreHorizontal;
}

long board::verticalDefensePoint(long row, long col, const long defenseScore[], const long attackScore[])
{
	int scoreVertical{ 0 };
	int myTokens{ 0 };
	int enemyTokens{ 0 };
	int myTokens2{ 0 };
	int enemyTokens2{ 0 };

	//count downward
	for (int count{ 1 }; count < 6 && count + row; count++) {
		if (pArr[row + count][col].getCheck() == 1)
			myTokens++;
		if (pArr[row + count][col].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row + count][col].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && row + count2 < size; count2++) {
				if (pArr[count2 + row][col].getCheck() == 1)
					myTokens2++;
				if (pArr[count2 + row][col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[count2 + row][col].getCheck() == 0) {
					break;
				}
			}
			break;
		}
	}

	//count upward
	for (int count{ 1 }; count < 6 && row - count >= 0; count++) {
		if (pArr[row - count][col].getCheck() == 1)
			myTokens++;
		if (pArr[row - count][col].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row - count][col].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && row - count2 >= 0; count++) {
				if (pArr[row - count2][col].getCheck() == 1)
					myTokens2++;
				if (pArr[row - count2][col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[row - count2][col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myTokens == 2)
		return 0;
	if (myTokens == 0)
		scoreVertical += defenseScore[enemyTokens] * 2;
	else
		scoreVertical += defenseScore[enemyTokens];

	if (enemyTokens >= enemyTokens2)
		scoreVertical -= 1;
	else
		scoreVertical -= 2;

	if (enemyTokens == 4)
		scoreVertical *= 2;

	return scoreVertical;
}

long board::diagonalDefensePoint1(long row, long col, const long defenseScore[], const long attackScore[])
{
	int scoreDiag1{ 0 };
	int myTokens{ 0 };
	int enemyTokens{ 0 };
	int myTokens2{ 0 };
	int enemyTokens2{ 0 };

	//move diagonally downward to the right
	for (int count{ 1 }; count < 6 && col + count < size && row + count < size; count++) {
		if (pArr[row + count][col + count].getCheck() == 1)
			myTokens++;
		if (pArr[row + count][col + count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row + count][col + count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && count2 + col < size && count2 + row < size; count2++) {
				if (pArr[count2 + row][count2 + col].getCheck() == 1)
					myTokens2++;
				if (pArr[count2 + row][count2 + col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[count2 + row][count2 + col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//move diagonally upward to the left
	for (int count{ 1 }; row - count >= 0 && count - col >= 0 && count < 6; count++) {
		if (pArr[row - count][col - count].getCheck() == 1) {
			myTokens++;
			break;
		}
		if (pArr[row - count][col - count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row - count][col - count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && col - count2 >= 0 && row - count2 >= 0; count2++) {
				if (pArr[row - count2][col - count2].getCheck() == 1) {
					myTokens2++;
					break;
				}
				if (pArr[row - count2][col - count2].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[row - count2][col - count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myTokens == 2)
		return 0;
	if (myTokens == 0)
		scoreDiag1 += defenseScore[enemyTokens] * 2;
	else
		scoreDiag1 += defenseScore[enemyTokens];

	if (enemyTokens >= enemyTokens2)
		scoreDiag1 -= 1;
	else
		scoreDiag1 -= 2;

	if (enemyTokens == 4)
		scoreDiag1 *= 2;

	return scoreDiag1;
}

long board::diagonalDefensePoint2(long row, long col, const long defenseScore[], const long attackScore[])
{
	int scoreDiag2{ 0 };
	int myTokens{ 0 };
	int enemyTokens{ 0 };
	int myTokens2{ 0 };
	int enemyTokens2{ 0 };

	//move diagonally downward to the left
	for (int count{ 1 }; count < 6 && col - count >= 0 && row + count < size; count++) {
		if (pArr[row + count][col - count].getCheck() == 1)
			myTokens++;
		if (pArr[row + count][col - count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row + count][col - count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && col - count2 >= 0 && count2 + row < size; count2++) {
				if (pArr[count2 + row][col - count2].getCheck() == 1)
					myTokens2++;
				if (pArr[count2 + row][col - count2].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[count2 + row][col - count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//move diagonally upward to the right
	for (int count{ 1 }; row - count >= 0 && count + col < size && count < 6; count++) {
		if (pArr[row - count][col + count].getCheck() == 1)
			myTokens++;
		if (pArr[row - count][col + count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row - count][col + count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && count2 + col < size && row - count2 >= 0; count2++) {
				if (pArr[row - count2][count2 + col].getCheck() == 1)
					myTokens2++;
				if (pArr[row - count2][count2 + col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[row - count2][count2 + col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myTokens == 2)
		return 0;
	if (myTokens == 0)
		scoreDiag2 += defenseScore[enemyTokens] * 2;
	else
		scoreDiag2 += defenseScore[enemyTokens];

	if (enemyTokens >= enemyTokens2)
		scoreDiag2 -= 1;
	else
		scoreDiag2 -= 2;

	if (enemyTokens == 4)
		scoreDiag2 *= 2;
		
	return scoreDiag2;
}

long board::horizontalAttackPoint(long row, long col, const long defenseScore[], const long attackScore[])
{
	long scoreHorizontal = 0;
	int myPieces = 0;
	int enemyPieces = 0;

	int myPieces2 = 0;
	int enemyPieces2 = 0;

	//check tokens/pieces to the right of the current position
	for (int count{ 1 }; count < 6 && count + col < size; count++) {
		if (pArr[row][count + col].getCheck() == 1)
			myPieces++;
		if (pArr[row][count + col].getCheck() == -1) {
			enemyPieces++;
			break;
		}
		if (pArr[row][count + col].getCheck() == 0) { //if there is no pieces its keep moving to the next position (to the right)
			//this 'for' block of code is counting the number of consecutive player tokens 'myPieces' to the right of the current position and the number of consecutive opponent tokens (enemyPieces) 
			//until either the end of the board or an empty position is encountered.
			for (int count2{ 2 }; count2 < 7 && count2 + col < size; count2++) {
				if (pArr[row][count2 + col].getCheck() == 1)
					myPieces2++;
				if (pArr[row][count + col].getCheck() == -1){
					enemyPieces2++;
					break;
				}
				if (pArr[row][count2 + col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//check tokens to the left of the current position
	for (int count{ 1 }; count < 6 && col - count >= 0; count++) {
		if (pArr[row][col - count].getCheck() == 1)
			myPieces++;
		if (pArr[row][col - count].getCheck() == -1) {
			enemyPieces++;
			break;
		}
		if (pArr[row][col - count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && col - count2 >= 0; count2++) {
				if (pArr[row][col - count2].getCheck() == 1)
					myPieces2++;
				if (pArr[row][col - count2].getCheck() == -1){
					enemyPieces2++;
				}
				if (pArr[row][col - count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//scoring based on the arrangement of tokens
	if (enemyPieces == 2) //if opponent have 2 consecutive tokens
		return 0; //indicate that play cant achieve victory in this direction due to being blocked
	if (enemyPieces == 0) //no consecutive opponent's token
		scoreHorizontal += attackScore[myPieces] * 2;
	else
		scoreHorizontal += attackScore[myPieces];
	//longer sequences of player tokens(my pieces) => the more desirable, and the score is adjusted accordingly.

	if (enemyPieces2 == 0) //consecutive opponent tokens separated by an empty space 
		//=> player has a chance to achieve a sequence of their own tokens with a gap. 
		scoreHorizontal += attackScore[myPieces2] * 2;
	else
		scoreHorizontal += attackScore[myPieces2];

	//The idea is that if there is a choice between two potential sequences with an empty space, the AI might prioritize the longer sequence to increase the chances of winning.
	//The subtraction is used to fine-tune the scoring based on this decision criterion.
	if (myPieces >= myPieces2)
		scoreHorizontal -= 1;
	else
		scoreHorizontal -= 2;

	if (myPieces == 4) //four consecutive player tokens is considered a stronger move, and the score is boosted.
		scoreHorizontal *= 2;
	if (myPieces == 0) // accounts for the defensive strategy when there are no consecutive player tokens, 
					  //and it emphasizes the importance of preventing the opponent from forming a winning sequence.
		scoreHorizontal += defenseScore[enemyPieces] * 2;
	else //if neither '4' nor '0'
		scoreHorizontal += defenseScore[enemyPieces];

	if (myPieces2 == 0)
		scoreHorizontal += defenseScore[enemyPieces2] * 2;
	else
		scoreHorizontal += defenseScore[enemyPieces2];

	return scoreHorizontal;
}

long board::verticalAttackPoint(long row, long col, const long defenseScore[], const long attackScore[])
{
	int scoreVertical{ 0 };

	int myTokens{ 0 };
	int enemyTokens{ 0 };
	int myTokens2{ 0 };
	int enemyTokens2{ 0 };

	//count downward
	for (int count{ 1 }; count < 6 && count + row; count++) {
		if (pArr[row + count][col].getCheck() == 1)
			myTokens++;
		if (pArr[row + count][col].getCheck() == -1){
			enemyTokens++;
			break;
		}
		if (pArr[row + count][col].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && row + count2 < size; count2++) {
				if (pArr[count2 + row][col].getCheck() == 1)
					myTokens2++;
				if (pArr[count2 + row][col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[count2 + row][col].getCheck() == 0) {
					break;
				}
			}
			break;
		}
	}

	//count upward
	for (int count{ 1 }; count < 6 && row - count >= 0; count++) {
		if (pArr[row - count][col].getCheck() == 1)
			myTokens++;
		if (pArr[row - count][col].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row - count][col].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && row - count2 >= 0; count++) {
				if (pArr[row - count2][col].getCheck() == 1)
					myTokens2++;
				if (pArr[row - count2][col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[row - count2][col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myTokens == 2)
		return 0;
	if (enemyTokens == 0)
		scoreVertical += attackScore[myTokens] * 2;
	else
		scoreVertical += attackScore[myTokens];

	if (enemyTokens2 == 0)
		scoreVertical += attackScore[myTokens2] * 2;
	else
		scoreVertical += attackScore[myTokens2];

	if (myTokens >= myTokens2)
		scoreVertical -= 1;
	else
		scoreVertical -= 2;

	if (myTokens == 4)
		scoreVertical *= 2;
	if (myTokens == 0)
		scoreVertical += defenseScore[enemyTokens] * 2;
	else
		scoreVertical += defenseScore[enemyTokens];

	if (myTokens2 == 0)
		scoreVertical += defenseScore[enemyTokens2] * 2;
	else
		scoreVertical += defenseScore[enemyTokens2];

	return scoreVertical;
}

long board::diagonalAttackPoint1(long row, long col, const long defenseScore[], const long attackScore[])
{
	int scoreDiag1{ 0 };
	int myTokens{ 0 };
	int enemyTokens{ 0 };
	int myTokens2{ 0 };
	int enemyTokens2{ 0 };

	//move diagonally downward to the right
	for (int count{ 1 }; count < 6 && col + count < size && row + count < size; count++) {
		if (pArr[row + count][col + count].getCheck() == 1)
			myTokens++;
		if (pArr[row + count][col + count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row + count][col + count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && count2 + col < size && count2 + row < size; count2++) {
				if (pArr[count2 + row][count2 + col].getCheck() == 1)
					myTokens2++;
				if (pArr[count2 + row][count2 + col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[count2 + row][count2 + col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//move diagonally upward to the left
	for (int count{ 1 }; row - count >= 0 && count - col >= 0 && count < 6; count++) {
		if (pArr[row - count][col - count].getCheck() == 1) {
			myTokens++;
			break;
		}
		if (pArr[row - count][col - count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row - count][col - count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && col - count2 >= 0 && row - count2 >= 0; count2++) {
				if (pArr[row - count2][col - count2].getCheck() == 1) {
					myTokens2++;
					break;
				}
				if (pArr[row - count2][col - count2].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[row - count2][col - count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myTokens == 2)
		return 0;
	if (enemyTokens == 0)
		scoreDiag1 += attackScore[myTokens] * 2;
	else
		scoreDiag1 += attackScore[myTokens];

	if (enemyTokens2 == 0)
		scoreDiag1 += attackScore[myTokens2] * 2;
	else
		scoreDiag1 += attackScore[myTokens2];

	if (myTokens >= myTokens2)
		scoreDiag1 -= 1;
	else
		scoreDiag1 -= 2;

	if (myTokens == 4)
		scoreDiag1 *= 2;
	if (myTokens == 0)
		scoreDiag1 += defenseScore[enemyTokens] * 2;
	else
		scoreDiag1 += defenseScore[enemyTokens];

	if (myTokens2 == 0)
		scoreDiag1 += defenseScore[enemyTokens2] * 2;
	else
		scoreDiag1 += defenseScore[enemyTokens2];

	return scoreDiag1;
}

long board::diagonalAttackPoint2(long row, long col, const long defenseScore[], const long attackScore[])
{
	int scoreDiag2{ 0 };
	int myTokens{ 0 };
	int enemyTokens{ 0 };
	int myTokens2{ 0 };
	int enemyTokens2{ 0 };

	//move diagonally downward to the left
	for (int count{ 1 }; count < 6 && col - count >= 0 && row + count < size; count++) {
		if (pArr[row + count][col - count].getCheck() == 1)
			myTokens++;
		if (pArr[row + count][col - count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row + count][col - count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && col - count2 >= 0 && count2 + row < size; count2++) {
				if (pArr[count2 + row][col - count2].getCheck() == 1)
					myTokens2++;
				if (pArr[count2 + row][col - count2].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[count2 + row][col - count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	//move diagonally upward to the right
	for (int count{ 1 }; row - count >= 0 && count + col < size && count < 6; count++) {
		if (pArr[row - count][col + count].getCheck() == 1)
			myTokens++;
		if (pArr[row - count][col + count].getCheck() == -1) {
			enemyTokens++;
			break;
		}
		if (pArr[row - count][col + count].getCheck() == 0) {
			for (int count2{ 2 }; count2 < 7 && count2 + col < size && row - count2 >= 0; count2++) {
				if (pArr[row - count2][count2 + col].getCheck() == 1)
					myTokens2++;
				if (pArr[row - count2][count2 + col].getCheck() == -1) {
					enemyTokens2++;
					break;
				}
				if (pArr[row - count2][count2 + col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	if (myTokens == 2)
		return 0;
	if (enemyTokens == 0)
		scoreDiag2 += attackScore[myTokens] * 2;
	else
		scoreDiag2 += attackScore[myTokens];

	if (enemyTokens2 == 0)
		scoreDiag2 += attackScore[myTokens2] * 2;
	else
		scoreDiag2 += attackScore[myTokens2];

	if (myTokens >= myTokens2)
		scoreDiag2 -= 1;
	else
		scoreDiag2 -= 2;

	if (myTokens == 4)
		scoreDiag2 *= 2;
	if (myTokens == 0)
		scoreDiag2 += defenseScore[enemyTokens] * 2;
	else
		scoreDiag2 += defenseScore[enemyTokens];

	if (myTokens2 == 0)
		scoreDiag2 += defenseScore[enemyTokens2] * 2;
	else
		scoreDiag2 += defenseScore[enemyTokens2];

	return scoreDiag2;
}

int board::checkWinRow(int x, int y, int value)
{
	int row, col; //row = x, col = y
	int loop = 1;
	int won = -1;
	int check2head = 0;
	int countLeftRow = 0;
	int countRightRow = 0;
	row = (x - left - 2) / 4;
	//'x': x coordinate of the specified position on the game board; 'left': leftmost coordinate, represents the x-coordinate where the game board is started; '-2': offset cause by margin/border of the board
	//the calculation designed to convert the x coordinate of a position into the corresponding row index.
	col = (y - top - 1) / 2; //same here

	int rightRow, leftRow;
	rightRow = leftRow = row;

	while (pArr[col][leftRow].getCheck() == value) { //while loop continue as long as the check value of the cell at the specified position is equal to the specified 'value'(value is either -1(X) or 1(O) here)
		win.push_back(pArr[col][leftRow]); //if the check value =  specified 'value', the position (pArr[col][leftRow]) is being added to the win vector
		//win vector used to store the coordinates and check the values of the winning cells
		countLeftRow++; //increase to keep track with the number of consecutive occurrences of the specified value (to the left of the current position)
		if (leftRow == 0)
			break; //ensure it doesnt go beyond the left boundary of the board.
		leftRow--; //move to the next position to the left on the same row.
	}

	while (pArr[col][rightRow].getCheck() == value) {
		win.push_back(pArr[col][rightRow]);
		countRightRow++;
		if (rightRow == size-1) //move to the right, first element of the array is '0' and the last element is 'size-1'.
			break; //stop when reach to the rightmost boundary
		rightRow++;
	}

	if (pArr[col][leftRow].getCheck() == -value && pArr[col][rightRow].getCheck() == -value)
		//checks if there are consecutive opponent marks (-value) at both ends of the winning sequence.
		check2head = 1;

	if ((countLeftRow + countRightRow - 1) == 5 && (check2head == 0)) //minus 1 bc including the current position. This checks if the total count of consecutive marks in both directions (to the left and right) is equal to 5.
		won = 1; //win if there are 5 consecutive marks and there are no consecutive opponent marks at both ends.
	else
		won = 0;

	if (won == 1) {
		//PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		while (loop < 30) {
			textColor(rand() % 15 + 1);
			for (int i{ 0 }; i < win.size(); i++) {
				Console::gotoXY(win[i].getX(), win[i].getY());
				//uses _Common::gotoXY to set the cursor position on the console and prints either "X" or "O" based on the check value of that position.
				if (win[i].getCheck() == 1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100); //100 millisecond
			loop++;
		}
	}
	else
		win.clear(); //removes all elements from the vector, leaving it with a size of 0.
	return won;
}

int board::checkWinCol(int x, int y, int value)
{
	int row, col;
	int loop = 1;
	int won = -1;
	int check2head = 0;
	int countTopCol = 0;
	int countBottomCol = 0;

	row = (x - left - 2) / 4;
	col = (y - top - 1) / 2;
	// Convert pixel coordinates to array indices

	int upperCol, lowerCol; //Counters for the upper and lower columns
	upperCol = lowerCol = col;

	//check for a win in vertical direction
	while (pArr[upperCol][row].getCheck() == value) {
		win.push_back(pArr[upperCol][row]);
		countTopCol++;
		if (upperCol == 0)
			break;
		upperCol--;
	}

	while (pArr[lowerCol][row].getCheck() == value) {
		win.push_back(pArr[lowerCol][row]);
		countBottomCol++;
		if (lowerCol == size - 1)
			break;
		lowerCol++;
	}

	if (pArr[upperCol][row].getCheck() == -value && pArr[lowerCol][row].getCheck() == -value) {
		check2head = 1;
	}
	else
		check2head = 0;

	if (won == 1) {
		//PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		while (loop < 30) {
			textColor(rand() % 15 + 1);
			for (int i{ 0 }; i < win.size(); i++) {
				Console::gotoXY(win[i].getX(), win[i].getY());
				//uses _Common::gotoXY to set the cursor position on the console and prints either "X" or "O" based on the check value of that position.
				if (win[i].getCheck() == 1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100); //100 millisecond
			loop++;
		}
	}
	else
		win.clear();

	return won;
}

int board::checkWinDiag1(int x, int y, int value)
{
	int row, col;
	int loop = 1;
	int won = -1;
	int check2ends = 0;
	int countUpperDiag = 0;
	int countLowerDiag = 0;

	row = (x - left - 2) / 4;
	col = (y - top - 1) / 2;
	// Convert pixel coordinates to array indices

	int upperCol, lowerCol; //Counters for the upper and lower of the column
	int rightRow, leftRow; //same but with row

	upperCol = lowerCol = col;
	rightRow = leftRow = row;

	while (pArr[upperCol][rightRow].getCheck() == value) {
		countUpperDiag++;
		win.push_back(pArr[upperCol][rightRow]);
		if (upperCol == 0 || rightRow == size - 1)
			break;
		upperCol--;
		rightRow++;
	}

	while (pArr[lowerCol][leftRow].getCheck() == value) {
		win.push_back(pArr[lowerCol][leftRow]);
		countLowerDiag++;
		if (lowerCol == size - 1 || leftRow == 0)
			break;
		lowerCol++; //is used to move to the next row (downward) in the column
		leftRow--;
	}

	if (pArr[upperCol][rightRow].getCheck() == -value && pArr[lowerCol][leftRow].getCheck() == -value)
		check2ends = 1;
	if (countUpperDiag + countLowerDiag - 1 == 5 && check2ends == 1)
		won = 1;
	else
		won = 0;

	if (won == 1) {
		//PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		while (loop < 30) {
			textColor(rand() % 15 + 1);
			for (int i{ 0 }; i < win.size(); i++) { //win.size() function is used to retrieve the number of elements (positions) in the win vector
				Console::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << 'X';
				else
					cout << 'O';
			}
			loop++;
			Sleep(100);
		}
	}
	else
		win.clear();

	return won;
}

int board::checkWinDiag2(int x, int y, int value)
{
	int row, col;
	int loop = 1;
	int won = -1;
	int check2ends = 0;
	int countUpperDiag = 0;
	int countLowerDiag = 0;

	row = (x - left - 2) / 4;
	col = (y - top - 1) / 2;
	// Convert pixel coordinates to array indices

	int upperCol, lowerCol; //Counters for the upper and lower of the column
	int rightRow, leftRow; //same but with row

	upperCol = lowerCol = col;
	rightRow = leftRow = row;

	while (pArr[upperCol][leftRow].getCheck() == value) {
		countUpperDiag++;
		win.push_back(pArr[upperCol][leftRow]);
		if (upperCol == 0 || leftRow == 0)
			break;
		upperCol--;
		rightRow--;
	}

	while (pArr[lowerCol][rightRow].getCheck() == value) {
		countLowerDiag++;
		win.push_back(pArr[lowerCol][rightRow]);
		if (lowerCol == size - 1 || rightRow == size - 1)
			break;
		lowerCol++;
		rightRow++;
	}

	if (pArr[upperCol][leftRow].getCheck() == -value && pArr[lowerCol][rightRow].getCheck() == -value)
		check2ends = 1;
	if (countUpperDiag + countLowerDiag - 1 == 5 && check2ends == 1)
		won = 1;
	else
		won = 0;

	if (won == 1) {
		//PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		while (loop < 30) {
			textColor(rand() % 15 + 1);
			for (int i{ 0 }; i < win.size(); i++) {
				Console::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == 1)
					cout << 'O';
				else
					cout << 'X';
			}
			loop++;
			Sleep(100);
		}
	}
	else
		win.clear();

	return won;
}

board::board() //deallocate the memory used for 'parr' 2d array
{
	for (int i{ 0 }; i < size; i++) {
		delete[] pArr[i];
	}
	delete[] pArr; //default constructor is used as destructor here. might lead to memory leak
}

board::board(int pSize, int pX, int pY)
{
	size = pSize;
	left = pX;
	top = pY;
	//initialize the size, left and top coordinates of the board

	pArr = new Point * [pSize]; //dynamically allocates memory for 2D array	'pArr' using 'new' operator
	for (int i{ 0 }; i < pSize; i++) {
		pArr[i] = new Point[pSize];
	}
}

board::~board()
{
}

//board::~board()
//{
//	for (int i{ 0 }; i < size; i++) {
//		delete[] pArr[i];
//	}
//	delete[] pArr; //default constructor is actually used as destructor here. might lead to memory leak
//}
