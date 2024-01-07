#include"Point.h"
#include"board.h"
#include"Console.h"
#include"Game.h"
#include"Play.h"
#include<string.h>

int main() {
	int n{ 100 };
	Console::fixConsoleWindow();
	Console::setConsoleWindow(1000, 600);
	mainMenu(n);
	system("pause");

	return 0;
}