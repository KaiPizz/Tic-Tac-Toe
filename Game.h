#pragma once
#include"board.h"
#include"Point.h"
#include"Play.h"
#include"Console.h"

#include"board.h"

void player1();
void player2();
void Draw();
void player1Win();
void player2Win();
void playerDraw();
void Box();
//handle Win - Lose - Draw effect

class Game
{
private:
	board* newBoard; //declare a pointer to board class
	bool turn{};
	int x{}, y{};
	int keys{}; //get keys from keyboard
	bool loop; //true continue play - false break;
	int scorePlayer1{}; //number of matches player 1 won
	int scorePlayer2{}; //number of matches player 2 won
	int setMode{}; //read file to identify game mode
	//'-31': mode PvP, 'O' go first
	//'-30': mode PvP, 'X' go first
	//'-4': mode PvC(Easy), Bot 'O' go first
	//'-5': mode PvC(Hard), Bot 'O' go first

public:
	void setCountXO() {
		newBoard->countX = 0;
		newBoard->countO = 0;
	}

	bool getTurn() {
		return turn;
	}
	void setTurn() {
		turn = !turn; //reverse turn 
	}

	int getMode() {
		return setMode;
	}

	//get score
	int getScore1() {
		return scorePlayer1;
	}
	int getScore2() {
		return scorePlayer2;
	}

	//set score = 0
	void setScore1() {
		scorePlayer1 = 0;
	}
	void setScore2() {
		scorePlayer2 = 0;
	}

	int getKey() {
		return keys;
	}

	void setKey(int a) {
		keys = a;
	}

	bool isContinue() { 	//continue the game
		return loop;
	}
	char waitKeyboard(); //wait for the input key
	char askContinue(); //play again or quit

	void startGame(); //initialize the game
	void exitGame(); //exit

	int finishProcess(int x, int y); //check Win-lose to continue
	bool processCheckBoard(); //marked 'X' and 'O' in the board

	void goRight(); //D
	void goLeft(); //A
	void goUp(); //W
	void goDown(); //S

	void setX(int X) {
		x = X;
	}
	void setY(int Y) {
		y = Y;
	}

	//return the value of the coordinates when clicked 'Enter'
	int getXatEnter();
	int getYatEnter();

	void findMove(); //hard bot
	void findMove2(); //easy bot

	int countMadeMove();

	//Game();
	~Game();
	Game(int pSize, int pLeft, int pTop);
};