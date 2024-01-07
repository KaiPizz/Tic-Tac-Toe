#include "Game.h"
#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>

using namespace std;

void player1()
{
	//int i{ 10 }, j{ 10 };
	cout << "Player 1 Win!!";
}

void player2()
{
	//int i{ 10 }, j{ 10 };
	cout << "Player 2 Win!!";
}

void Draw()
{
	cout << "Draw!!";
}

void player1Win()
{
	//hideMouse();
	int check{ 1 };
	Box();
	while (check < 30) {
		player1();
		Sleep(200);
		check++;
	}
}

void player2Win()
{
	hideMouse();
	int check{ 1 };
	Box();
	while (check < 30) {
		player2();
		Sleep(200);
		check++;
	}
}

void playerDraw()
{
	hideMouse();
	int check{ 1 };
	Box();
	while (check < 30) {
		Draw();
		Sleep(200);
		check++;
	}
}

void Box() //draw box
{
	int i = 8, j = 8;
	Console::gotoXY(i, j);
	for (int i = 0; i < 110; i++) {
		textColor(rand() % 15 + 1);
		Sleep(1);
		cout << char(178);
	}
	Console::gotoXY(i, j + 14);
	for (int i = 0; i < 110; i++) {
		textColor(rand() % 15 + 1);
		Sleep(1);
		cout << char(178);
	}
	textColor(LightAqua);
	Console::gotoXY(50, j + 18);
	cout << "Y   : Play Again";
	Console::gotoXY(50, j + 19);
	cout << "ESC : BACK";
}

char Game::waitKeyboard()
{
	keys = toupper(_getch()); //'toupper' convert a given char to their uppercase, '_getch' read the char input from the keyboard by return the ASCII value of the char
	return keys;
}

char Game::askContinue()
{
	Console::gotoXY(0, newBoard->getYAt(newBoard->getSize(), newBoard->getSize()));
	return waitKeyboard();
}

void Game::startGame()
{
	system("cls"); //clear console
	newBoard->resetData();
	newBoard->drawBoard();
	x = newBoard->getXAt(0, 0); //initialize
	y = newBoard->getYAt(0, 0);

	if (turn == true) {
		textColor(Blue);
		Console::gotoXY(SIZE * 4 + 30, 25);
		cout << "Player 1's Turn";
	}
	else {
		textColor(Red);
		Console::gotoXY(SIZE * 4 + 30, 25);
		cout << "Player 2's Turn";
	}

	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 30, 4);
	cout << newBoard->countO;
	textColor(Red);
	Console::gotoXY(SIZE * 4 + 30, 14);
	cout << newBoard->countX;
}

void Game::exitGame()
{
	loop = false;
}

int Game::finishProcess(int x, int y)
{
	Console::gotoXY(0, newBoard->getYAt(newBoard->getSize(), newBoard->getSize()));
	int Winner = newBoard->checkWin(x, y);

	switch (Winner) {
	case 1:
		system("cls");
		player1Win();
		break;
	case -1:
		system("cls");
		player2Win();
		break;
	case 0:
		system("cls");
		playerDraw();
		break;
	case 2:
		turn = !turn;
	}
	Console::gotoXY(x, y);
	return Winner;
}

bool Game::processCheckBoard()
{
	switch (newBoard->checkBoard(x, y, turn)) {
	case 1: //'O'
		textColor(Blue); //O on board
		cout << "O";

		Console::gotoXY(SIZE * 4 + 30, 4);
		cout << newBoard->countO;

		textColor(Red);
		Console::gotoXY(SIZE * 4 + 30, 14);
		cout << newBoard->countX;

		cout << "Player 2's turn!";
		Console::gotoXY(x, y);
		break;

	case -1: //'X'
		textColor(Red); //X on board
		cout << "X";

		textColor(Blue);
		Console::gotoXY(SIZE * 4 + 30, 4);
		cout << newBoard->countO;
		Console::gotoXY(SIZE * 4 + 30, 26);
		cout << "Player 1's Turn!";

		textColor(Red);
		Console::gotoXY(SIZE * 4 + 30, 14);
		cout << newBoard->countX;
		break;
		
	case 0:
		return false;
		break;
	}
	return true;
}

//the board is being initialize from top left corner (0,0) so we need to set the end-border to goRight and goDown
void Game::goRight()
{
	if (x < newBoard->getXAt(newBoard->getSize(),newBoard->getSize())) {
		x += 4;
		Console::gotoXY(x, y);
	}
}

void Game::goLeft()
{
	if (x > newBoard->getXAt(0, 0)) {
		x -= 4;
		Console::gotoXY(x, y);
	}
}

void Game::goUp()
{
	if (y > newBoard->getYAt(0, 0)) {
		y -= 2;
		Console::gotoXY(x, y);
	}
}

void Game::goDown()
{
	if (y < newBoard->getYAt(newBoard->getSize(), newBoard->getSize())) {
		y += 2;
		Console::gotoXY(x, y);
	}
}

int Game::getXatEnter()
{
	return x;
}

int Game::getYatEnter()
{
	return y;
}

void Game::findMove() //hard
{
	x = newBoard->searchHardMove().getX();
	y = newBoard->searchHardMove().getY();
}

void Game::findMove2() //easy
{
	x = newBoard->searchEasyMove().getX();
	y = newBoard->searchEasyMove().getY();
}

int Game::countMadeMove()
{
	return newBoard->countO + newBoard->countX;
}

Game::Game(int pSize, int pLeft, int pTop)
{
	newBoard = new board(pSize, pLeft, pTop);
	loop = turn = true;
	keys = -1;
	x = pLeft;
	y = pTop;
}

Game::~Game()
{
	delete newBoard;
}

