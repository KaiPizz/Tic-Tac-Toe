#include "Play.h"
#include<vector>
#include<Windows.h>
#include<mmsystem.h>
#include<iostream>
#include<fstream> //ifstream - read, ofstream - write, fstream - both read & write

using namespace std;

struct Name {
	char data[30];
};
vector <Name> ch;

int	Mode(char a[30])
{
	int d1{}, d2{}, modes{};
	system("cls"); //clears the console screen before perform any other operations
	ifstream file; //declares an object of type 'ifstream' named 'file'. Used to read input from files
	file.open(a, ios::in); //open a file, its name specified by the variable a (char a[30]) in input mode (ios::in)
	if (!file) { //if file open fail
		Console::gotoXY(35, 46); //set cursor position of the console to (35,46), to print out the error message as below.
		cout << "THE SELECTED FILE DOES NOT EXIST!" << endl;
		Sleep(1000); //pause for 1000 millisecond = 1 second
		mainMenu(99);
	}
	else  //if the file successful opened
		file >> d1 >> d2 >> modes;

	file.close(); //close file after read
	return modes;
}

//void readNameFile()
//{
//	textColor(LightAqua);
//	Console::gotoXY(60, 18);
//	cout << "LIST FILE NAME: " << endl;
//	int i{ 19 };
//	ifstream file;
//	file.open("Name.txt", ios::in);
//	while (!file.eof()) { //end-of-file: returns nonzero (meaning TRUE) when there are no more data to be read from an input file stream, and zero (meaning FALSE) otherwise.
//		char s[30];
//		file >> s;
//		Console::gotoXY(50, i);
//		cout << s;
//		i++;
//	}
//	file.close();
//}

void print1()
{
	//T
	int x = 0, y = 2;
	textColor(rand() % 15 + 1);
	Console::gotoXY(x, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x, y + 2);				   cout << "oooooooooooooooooooooooooo";

	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 5);						cout << "oooooooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 8);						cout << "oooooooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 10);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 11);						cout << "oooooooo";

	//i
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 20, y + 6);						cout << "ooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 20, y + 8);						cout << "ooo";
	Console::gotoXY(x + 20, y + 9);						cout << "ooo";
	Console::gotoXY(x + 20, y + 10);					cout << "ooo";
	Console::gotoXY(x + 20, y + 11);					cout << "ooo";

	//c
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 28, y + 6);				    cout << "oooooo";
	Console::gotoXY(x + 28 - 2, y + 7);			  cout << "oooo";
	Console::gotoXY(x + 28 - 2, y + 8);			  cout << "oooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 28 - 2, y + 9);			  cout << "oooo";
	Console::gotoXY(x + 28 - 1, y + 10);		    cout << "oooo";
	Console::gotoXY(x + 28 + 1, y + 11);			  cout << "oooooo";

	//T
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 38, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 38, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 38, y + 2);				   cout << "oooooooooooooooooooooooooo";
	textColor(rand() % 5 + 1);
	Console::gotoXY(x + 38 + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 5);						cout << "oooooooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 38 + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 8);						cout << "oooooooo";
	textColor(rand() % 3 + 1);
	Console::gotoXY(x + 38 + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 11);					cout << "oooooooo";

	//a
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 61, y + 6);				           cout << "oo";
	Console::gotoXY(x + 60, y + 7);				          cout << "oooo";
	Console::gotoXY(x + 59, y + 8);				         cout << "oooooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 58, y + 9);				        cout << "ooo  ooo";
	Console::gotoXY(x + 58, y + 10);				    cout << "oooooooo";
	Console::gotoXY(x + 58, y + 11);				    cout << "oo    oo";

	//c
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 71, y + 6);				    cout << "ooooooo";
	Console::gotoXY(x + 72 - 3, y + 7);			  cout << "oooo";
	Console::gotoXY(x + 72 - 3, y + 8);			  cout << "oooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 72 - 3, y + 9);			  cout << "oooo";
	Console::gotoXY(x + 72 - 2, y + 10);		    cout << "oooo";
	Console::gotoXY(x + 72, y + 11);			      cout << "oooooo";

	//T
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 81, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 81, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 81, y + 2);				   cout << "oooooooooooooooooooooooooo";
	textColor(rand() % 5 + 1);
	Console::gotoXY(x + 81 + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 5);						cout << "oooooooo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 81 + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 8);						cout << "oooooooo";
	textColor(rand() % 3 + 1);
	Console::gotoXY(x + 81 + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 11);					cout << "oooooooo";

	//o
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 101, y + 6);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 7);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 8);					cout << "oo    oo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 101, y + 9);					cout << "oo    oo";
	Console::gotoXY(x + 101, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 11);					cout << "oooooooo";

	//E dont know how to 'e'
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 110, y + 6);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 7);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 8);					cout << "oo";
	textColor(rand() % 15 + 1);
	Console::gotoXY(x + 110, y + 9);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 10);					cout << "oo";
	Console::gotoXY(x + 110, y + 11);					cout << "oooooooo";
}

void print2()
{
	//T
	Sleep(200);
	int x = 0, y = 2;
	textColor(LightGreen);
	Console::gotoXY(x, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x, y + 2);				   cout << "oooooooooooooooooooooooooo";

	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 5);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 8);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 10);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 11);						cout << "oooooooo";

	//i
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 20, y + 6);						cout << "ooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 20, y + 8);						cout << "ooo";
	Console::gotoXY(x + 20, y + 9);						cout << "ooo";
	Console::gotoXY(x + 20, y + 10);					cout << "ooo";
	Console::gotoXY(x + 20, y + 11);					cout << "ooo";

	//c
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 28, y + 6);				    cout << "oooooo";
	Console::gotoXY(x + 28 - 2, y + 7);			  cout << "oooo";
	Console::gotoXY(x + 28 - 2, y + 8);			  cout << "oooo";
	//textColor(rand() % 15 + 0.5);
	Console::gotoXY(x + 28 - 2, y + 9);			  cout << "oooo";
	Console::gotoXY(x + 28 - 1, y + 10);		    cout << "oooo";
	Console::gotoXY(x + 28 + 1, y + 11);			  cout << "oooooo";

	//T
	textColor(Aqua);
	Console::gotoXY(x + 38, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 38, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 38, y + 2);				   cout << "oooooooooooooooooooooooooo";
	//textColor(rand() % 5 + 1);
	Console::gotoXY(x + 38 + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 5);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 38 + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 8);						cout << "oooooooo";
	//textColor(rand() % 3 + 1);
	Console::gotoXY(x + 38 + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 11);					cout << "oooooooo";

	//a
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 61, y + 6);				           cout << "oo";
	Console::gotoXY(x + 60, y + 7);				          cout << "oooo";
	Console::gotoXY(x + 59, y + 8);				         cout << "oooooo";
	Console::gotoXY(x + 58, y + 9);				        cout << "ooo  ooo";
	Console::gotoXY(x + 58, y + 10);				    cout << "oooooooo";
	Console::gotoXY(x + 58, y + 11);				    cout << "oo    oo";

	//c
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 71, y + 6);				    cout << "ooooooo";
	Console::gotoXY(x + 72 - 3, y + 7);			  cout << "oooo";
	Console::gotoXY(x + 72 - 3, y + 8);			  cout << "oooo";
	Console::gotoXY(x + 72 - 3, y + 9);			  cout << "oooo";
	Console::gotoXY(x + 72 - 2, y + 10);		    cout << "oooo";
	Console::gotoXY(x + 72, y + 11);			      cout << "oooooo";

	//T
	textColor(Yellow);
	Console::gotoXY(x + 81, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 81, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 81, y + 2);				   cout << "oooooooooooooooooooooooooo";
	//textColor(rand() % 5 + 1);
	Console::gotoXY(x + 81 + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 5);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 81 + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 8);						cout << "oooooooo";
	//textColor(rand() % 3 + 1);
	Console::gotoXY(x + 81 + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 11);					cout << "oooooooo";

	//o
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 101, y + 6);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 7);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 8);					cout << "oo    oo";
	Console::gotoXY(x + 101, y + 9);					cout << "oo    oo";
	Console::gotoXY(x + 101, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 11);					cout << "oooooooo";

	//E dont know how to 'e'
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 110, y + 6);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 7);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 8);					cout << "oo";
	Console::gotoXY(x + 110, y + 9);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 10);					cout << "oo";
	Console::gotoXY(x + 110, y + 11);					cout << "oooooooo";
}

void print3()
{
	//T
	//Sleep(200);
	int x = 0, y = 2;
	textColor(LightGreen);
	Console::gotoXY(x, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x, y + 2);				   cout << "oooooooooooooooooooooooooo";

	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 5);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 8);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 10);						cout << "oooooooo";
	Console::gotoXY(x + 9, y + 11);						cout << "oooooooo";

	//i
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 20, y + 6);						cout << "ooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 20, y + 8);						cout << "ooo";
	Console::gotoXY(x + 20, y + 9);						cout << "ooo";
	Console::gotoXY(x + 20, y + 10);					cout << "ooo";
	Console::gotoXY(x + 20, y + 11);					cout << "ooo";

	//c
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 28, y + 6);				    cout << "oooooo";
	Console::gotoXY(x + 28 - 2, y + 7);			  cout << "oooo";
	Console::gotoXY(x + 28 - 2, y + 8);			  cout << "oooo";
	//textColor(rand() % 15 + 0.5);
	Console::gotoXY(x + 28 - 2, y + 9);			  cout << "oooo";
	Console::gotoXY(x + 28 - 1, y + 10);		    cout << "oooo";
	Console::gotoXY(x + 28 + 1, y + 11);			  cout << "oooooo";

	//T
	textColor(Blue);
	Console::gotoXY(x + 38, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 38, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 38, y + 2);				   cout << "oooooooooooooooooooooooooo";
	//textColor(rand() % 5 + 1);
	Console::gotoXY(x + 38 + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 5);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 38 + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 8);						cout << "oooooooo";
	//textColor(rand() % 3 + 1);
	Console::gotoXY(x + 38 + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 38 + 9, y + 11);					cout << "oooooooo";

	//a
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 61, y + 6);				           cout << "oo";
	Console::gotoXY(x + 60, y + 7);				          cout << "oooo";
	Console::gotoXY(x + 59, y + 8);				         cout << "oooooo";
	Console::gotoXY(x + 58, y + 9);				        cout << "ooo  ooo";
	Console::gotoXY(x + 58, y + 10);				    cout << "oooooooo";
	Console::gotoXY(x + 58, y + 11);				    cout << "oo    oo";

	//c
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 71, y + 6);				    cout << "ooooooo";
	Console::gotoXY(x + 72 - 3, y + 7);			  cout << "oooo";
	Console::gotoXY(x + 72 - 3, y + 8);			  cout << "oooo";
	Console::gotoXY(x + 72 - 3, y + 9);			  cout << "oooo";
	Console::gotoXY(x + 72 - 2, y + 10);		    cout << "oooo";
	Console::gotoXY(x + 72, y + 11);			      cout << "oooooo";

	//T
	textColor(Yellow);
	Console::gotoXY(x + 81, y);					   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 81, y + 1);				   cout << "oooooooooooooooooooooooooo";
	Console::gotoXY(x + 81, y + 2);				   cout << "oooooooooooooooooooooooooo";
	//textColor(rand() % 5 + 1);
	Console::gotoXY(x + 81 + 9, y + 3);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 4);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 5);						cout << "oooooooo";
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 81 + 9, y + 6);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 7);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 8);						cout << "oooooooo";
	//textColor(rand() % 3 + 1);
	Console::gotoXY(x + 81 + 9, y + 9);						cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 81 + 9, y + 11);					cout << "oooooooo";

	//o
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 101, y + 6);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 7);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 8);					cout << "oo    oo";
	Console::gotoXY(x + 101, y + 9);					cout << "oo    oo";
	Console::gotoXY(x + 101, y + 10);					cout << "oooooooo";
	Console::gotoXY(x + 101, y + 11);					cout << "oooooooo";

	//E dont know how to 'e'
	//textColor(rand() % 15 + 1);
	Console::gotoXY(x + 110, y + 6);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 7);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 8);					cout << "oo";
	Console::gotoXY(x + 110, y + 9);					cout << "oooooooo";
	Console::gotoXY(x + 110, y + 10);					cout << "oo";
	Console::gotoXY(x + 110, y + 11);					cout << "oooooooo";
}

void screen()
{
	int check{ 1 };
	while (check < 20)
	{
		print1();
		Sleep(100);
		check++;
	}
}

void textColor(int n)
{
	HANDLE consoleColor;
	consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleColor, n);
}

void hideMouse()
{
	CONSOLE_CURSOR_INFO in4;
	in4.bVisible = FALSE;
	in4.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &in4);
}

void showMouse()
{
	CONSOLE_CURSOR_INFO in4;
	in4.bVisible = TRUE; //show mouse
	in4.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &in4);
}

void mainMenu(int a)
{
	hideMouse();
	int x{ 50 };
	int y{ 20 };
	int i{};
	char s[30] = " ";
	int check = 1;
	textColor(Gray);
	
	Console::gotoXY(50, 20);
	cout << "Player Vs Player" << endl;

	Console::gotoXY(50, 21);
	cout << "Player Vs Bot (Easy)" << endl;

	Console::gotoXY(50, 22);
	cout << "Player Vs Bot (Hard)" << endl;

	Console::gotoXY(50, 23);
	cout << "Help" << endl;

	Console::gotoXY(50, 24);
	cout << "About" << endl;

	Console::gotoXY(50, 25);
	cout << "Exit" << endl;

	Console::gotoXY(0, 27);
	cout << "..........'W-S' to move." << endl;
	
	Console::gotoXY(1, 28);
	cout << "..........'Enter' to select." << endl;

	if (a == 100) {
		//PlaySound(TEXT("nhacnen.wav"), NULL, SND_FILENAME | SND_ASYNC);
		screen();
		print2();
	}
	else 
		print3();

	//set color change to each that we move up/down the console 
	while (check) { //check = 1
		if (_kbhit) { //'_khbit': checks the console for keyboard input.
			switch (_getch()) { //'_getch': gets a character from the console without any echo.

			case 'w': //set color go up
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y > 20) {
					y--;
					Console::gotoXY(x, y);
				}

				if (y == 20) {
					textColor(Red);
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					textColor(defaultColor); //white
					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 21) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					textColor(Red);
					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 22) {
					textColor(defaultColor);
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					textColor(Red);
					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 23) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					textColor(Red);
					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 24) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					textColor(Red);
					Console::gotoXY(50, 24);
					cout << "About" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 25) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					textColor(Red);
					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}
				break;

			case 's': //set color go down
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y < 25) {
					y++;
					Console::gotoXY(x, y);
				}

				if (y == 20) {
					textColor(Red);
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					textColor(defaultColor); //white
					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 21) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					textColor(Red);
					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 22) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					textColor(Red);
					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 23) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					textColor(Red);
					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 24);
					cout << "About" << endl;

					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 24) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					textColor(Red);
					Console::gotoXY(50, 24);
					cout << "About" << endl;

					textColor(defaultColor);
					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}

				if (y == 25) {
					textColor(defaultColor); //white
					Console::gotoXY(50, 20);
					cout << "Player Vs Player" << endl;

					Console::gotoXY(50, 21);
					cout << "Player Vs Bot (Easy)" << endl;

					Console::gotoXY(50, 22);
					cout << "Player Vs Bot (Hard)" << endl;

					Console::gotoXY(50, 23);
					cout << "Help" << endl;

					Console::gotoXY(50, 24);
					cout << "About" << endl;

					textColor(Red);
					Console::gotoXY(50, 25);
					cout << "Exit" << endl;
				}
				break;

			case 13: //value keyboard of 'Enter' = 13
				//PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y == 20) {
					point a;
					a.score1 = 0;
					a.score2 = 0;

					int t = PvP(a, 0, s); //PvP
					if (t == 27) {
						system("cls");
						mainMenu(99);
					}
				}
				
				if (y == 21) {
					point a;
					a.score1 = 0;
					a.score2 = 0;
					int t = playerVsCom2(a, 0, s); //easy bot
					if (t == 27) {
						system("cls");
						mainMenu(99);
					}
				}

				if (y == 22) {
					point a;
					a.score1 = 0;
					a.score2 = 0;
					int t = playerVsCom(a, 0, s); //hard bot
					if (t == 27) {
						system("cls");
						mainMenu(99);
					}
				}

				if (y == 23) {
					Tutorial();
					mainMenu(99);
				}

				if (y == 24) {
					about();
					mainMenu(99);
				}

				if (y == 25)
					exit(0); 
				//'exit()' function causes the respective program to terminate as soon as the function is encountered, no matter it appears in the program listing.
				
				break;
			}
		}
	}
}

void printScoreBoard()
{
	textColor(LightYellow);
	for (int i{ 1 }; i < SIZE * 2; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 18, i);
		cout << char(219); //https://www.ascii-code.com/219 char full block
	}

	textColor(Yellow);
	for (int i{ 1 }; i < SIZE * 2; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 17,i);
		cout << char(219);
	}

	textColor(White);
	Sleep(1);
	Console::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 + 1);
	cout << "	SCORE BOARD	  ";

	for (int i{ 0 }; i < (SIZE * 2 - 1) / 2 - 2; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 1, i + 1);
		cout << char(186); //'║' https://www.ascii-code.com/186
	}
	Sleep(1);
	Console::gotoXY(SIZE * 4 + 1, 0);
	cout << char(187); //https://www.ascii-code.com/187

	Console::gotoXY(SIZE * 4 + 1, SIZE * 2);
	cout << char(188); //https://theasciicode.com.ar/extended-ascii-code/box-drawing-character-double-line-lower-right-corner-ascii-code-188.html
		
	for (int i{ (SIZE * 2 - 1) / 2 + 3 }; i < SIZE * 2 - 1; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 - 1, i + 1);
		cout << char(186); //'║'
	}

	//border
	Console::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 - 1);
	cout << char(200); //'╚'
	for (int i{ 0 }; i < 15; i++) {
		Sleep(1); 
		cout << char(205); //'═'
	}
	Console::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 + 3);
	cout << char(201); //'╔'
	for (int i = 0; i < 15; i++)
	{
		Sleep(1);
		cout << char(205); //'═'
	}

	//table 1
	Sleep(1);
	Console::gotoXY(SIZE * 4 + 19, 4);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254); // █ -> ═ -> ═ -> ═ -> ■
	for (int i{ 0 }; i < 8; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 25, i + 1);
		cout << char(219); //'█'
	}
	Console::gotoXY(SIZE * 4 + 25, 0);
	for (int i{ 0 }; i < 37; i++) {
		Sleep(1);
		cout << char(220); //'▄' https://theasciicode.com.ar/extended-ascii-code/bottom-half-block-ascii-code-220.html
	}
	for (int i{ 0 }; i < 8; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 61, i + 1);
		cout << char(219);
	}
	Console::gotoXY(SIZE*4+25, 8);
	for (int i{ 0 }; i < 37; i++) {
		Sleep(1);
		cout << char(223); //'▀'
	}

	//table 2
	Console::gotoXY(SIZE * 4 + 19, (SIZE * 2 - 1) / 2 + 1);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254); // █ -> ═ -> ═ -> ═ -> ■
	for (int i{ 0 }; i < 8; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 25, 12 + i);
		cout << char(219); //'█'
	}
	Console::gotoXY(SIZE * 4 + 25, 11);
	for (int i{ 0 }; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	for (int i{ 0 }; i < 8; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 61, 12 + i);
		cout << char(219);
	}
	Console::gotoXY(SIZE * 4 + 25, 21);
	for (int i{ 0 }; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}

	//table 3
	Sleep(1);
	Console::gotoXY(SIZE * 4 + 19, SIZE * 2 - 4);
	cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254); // █ -> ═ -> ═ -> ═ -> ■
	for (int i{ 0 }; i < 8; i++) {
		Sleep(1);	
		Console::gotoXY(SIZE * 4 + 25, SIZE * 2 - i);
		cout << char(219);
	}
	Console::gotoXY(SIZE * 4 + 25, SIZE * 2 - 10);
	for (int i{ 0 }; i < 37; i++) {
		Sleep(1);
		cout << char(220);
	}
	for (int i{ 0 }; i < 8; i++) {
		Sleep(1);
		Console::gotoXY(SIZE * 4 + 61, SIZE * 2 - i);
		cout << char(219);
	}
	Console::gotoXY(SIZE * 4 + 25, SIZE * 2);
	for (int i{ 0 }; i < 37; i++) {
		Sleep(1);
		cout << char(223);
	}

	Console::gotoXY(SIZE * 4 + 40, 2);
	cout << "PLAYER 1";
	Console::gotoXY(SIZE * 4 + 30, 4);
	cout << "O tokens: ";
	Console::gotoXY(SIZE * 4 + 30, 5);
	cout << "Number of matches won: ";

	Console::gotoXY(SIZE * 4 + 40, 12);
	cout << "PLAYER 2";
	Console::gotoXY(SIZE * 4 + 30, 14);
	cout << "X tokens: ";
	Console::gotoXY(SIZE * 4 + 30, 15);
	cout << "Number of matches won: ";

	Console::gotoXY(SIZE * 4 + 30, 27);
	cout << "-----------------------";
	Console::gotoXY(SIZE * 4 + 30, 28);
	cout << " W A S D : Move ";

	Console::gotoXY(SIZE * 4 + 30, 31);
	cout << " ESC : Exit ";

	Console::gotoXY(1, 1); //default
}

int playerVsCom(point& a, int load, char data[30]) //hard
{
	int k{ 0 }, n{ 100 };
	showMouse();
	Game g(SIZE, 0, 0); // Game(int pSize, pLeft, pTop)
	g.setCountXO();
	if (load == -5) {
		g.startGame();
		g.setTurn();
	}
	printScoreBoard();
	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 30, 25);
	cout << "Player vs Bot (HARD)";

	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 48, 5);
	cout << a.score1;

	textColor(Red);
	Console::gotoXY(SIZE * 4 + 48, 15);
	cout << a.score2;

	Console::gotoXY(2, 1);
	while (g.isContinue()) {
		if (!g.getTurn()) { //NOT operator -> if not get turn
			if (g.countMadeMove() == 0) {
				g.setX((SIZE * 2) - 2);
				g.setY(SIZE - 1);
				Console::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setKey(13); //'Enter' keyboard value
			}
			else {
				g.findMove();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				Console::gotoXY(x, y);
				Sleep(300); //3s
				g.setKey(13);
			}
		}
		else
			g.waitKeyboard();

		if (g.getKey() == 27) { //'Esc' = 27
			//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 27;
		}
		else {
			switch (g.getKey()) {
			case 'W':
				g.goUp();
				break;
			case 'A':
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.goLeft();
				break;
			case 'S':
				g.goDown();
				break;
			case 'D':
				g.goRight();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()) {
					switch (g.finishProcess(x,y)) {
					case -1:
						a.score1++;
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return playerVsCom(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return playerVsCom(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					case 0:
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return playerVsCom(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
	}
}

int playerVsCom2(point& a, int load, char data[30]) //easy
{
	int k{ 1 }, n{ 99 };
	showMouse();
	Game g(SIZE, 0, 0);
	g.setCountXO();
	if (load == -4) {
		g.startGame();
		g.setTurn();
	}
	printScoreBoard();
	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 30, 25);
	cout << "Player vs Bot (EASY)";

	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 48, 5);
	cout << a.score1;

	textColor(Red);
	Console::gotoXY(SIZE * 4 + 48, 15);
	cout << a.score2;

	Console::gotoXY(2, 1);
	while (g.isContinue()) {
		if (!g.getTurn()) { //NOT operator -> if not get turn
			if (g.countMadeMove() == 0) {
				g.setX((SIZE * 2) - 2);
				g.setY(SIZE - 1);
				Console::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setKey(13); //'Enter' keyboard value
			}
			else {
				g.findMove();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				Console::gotoXY(x, y);
				Sleep(300); //3s
				g.setKey(13);
			}
		}
		else
			g.waitKeyboard();

		if (g.getKey() == 27) { //'Esc' = 27
			//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 27;
		}
		else {
			switch (g.getKey()) {
			case 'W':
				g.goUp();
				break;
			case 'A':
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.goLeft();
				break;
			case 'S':
				g.goDown();
				break;
			case 'D':
				g.goRight();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()) {
					switch (g.finishProcess(x, y)) {
					case -1:
						a.score1++;
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return playerVsCom2(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return playerVsCom2(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					case 0:
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return playerVsCom2(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
	}
}

int PvP(point& a, int load, char data[30])
{
	int k{ 1 }, n{ 99 };
	showMouse();
	Game g(SIZE, 0, 0);
	g.setCountXO();
	if (load == -30) {
		g.setTurn();
		g.startGame();
	}
	else if (load == -31) {
		//g.setTurn();
		g.startGame();
	}
	printScoreBoard();
	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 30, 25);
	cout << "Player vs Player";

	textColor(Blue);
	Console::gotoXY(SIZE * 4 + 48, 5);
	cout << a.score1;

	textColor(Red);
	Console::gotoXY(SIZE * 4 + 48, 15);
	cout << a.score2;

	Console::gotoXY(2, 1);
	while (g.isContinue()) {
		g.waitKeyboard();
		if (g.getKey() == 27) { //Esc
			return 27;
		}
		else {
			switch (g.getKey()) {
			case 'W':
				g.goUp();
				break;
			case 'A':
				//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.goLeft();
				break;
			case 'S':
				g.goDown();
				break;
			case 'D':
				g.goRight();
				break;
			case 13:
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()) {
					switch (g.finishProcess(x, y)) {
					case -1:
						a.score1++;
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return PvP(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return PvP(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					case 0:
						while (k) {//0
							if (_kbhit()) { //The function _kbhitchecks the console for the last keystroke https://learn.microsoft.com/pl-pl/cpp/c-runtime-library/reference/kbhit?view=msvc-170
								switch (_getch()) { //getch() method pauses the Output Console until a key is pressed. https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
								case 'y':
									load = 0;
									return PvP(a, load, data);
									break;
								case '27': //Esc
									system("cls");
									mainMenu(n);
									break;
								}
							}
						}
						break;
					}	
				}
			}
		}
	}
}

void Tutorial()
{
	system("cls");
	print3();
	textColor(LightAqua);

	Console::gotoXY(60,18);
	cout << "HELP" << endl;

	Console::gotoXY(10,21);
	cout << "How to play:" << endl;

	Console::gotoXY(10, 22);
	cout << "1. Board has 18x18 squares." << endl;

	Console::gotoXY(10, 23);
	cout << "2. Players using 'W-A-S-D' key to move around the board and press 'Enter' to make the move." << endl;

	Console::gotoXY(10, 24);
	cout << "3. Rules: whoever reaches 5 consecutive tokens first and without enemy tokens at 2 ends is the Winner.";

	Console::gotoXY(10, 25);
	cout << "Enjoy :)" << endl;

	Console::gotoXY(60, 28);
	cout << "BACK" << endl;
	Console::gotoXY(55, 29);
	cout << "(press any key)" << endl;

	//wait for user input (any key pressed)
	char command = ' ';
	command = _getch(); //_getch() function returns the reading of the character. There is no error returned.

	system("cls");
}

void about()
{
	system("cls"); //clear console
	print3();
	textColor(LightAqua);
	Console::gotoXY(60, 18);
	cout << "ABOUT";

	Console::gotoXY(50, 21);
	cout << "C++ Project" << endl;

	Console::gotoXY(50, 22);
	cout << "Tic tac toe game with 2 modes." << endl;

	Console::gotoXY(50, 23);
	cout << "Imie i nazwisko: Gia Minh Han" << endl;

	Console::gotoXY(60, 26);
	cout << "BACK" << endl;
	Console::gotoXY(55, 27);
	cout << "(press any key)" << endl;

	//wait for user input (any key pressed)
	char command = ' ';
	command = _getch(); //_getch() function returns the reading of the character. There is no error returned.

	system("cls");
}
