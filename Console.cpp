#include "Console.h"

void Console::fixConsoleWindow() //function modified to remove the styles of Window console and then set the modified style back. Used to restrict user from resizing the Window console
{
	HWND myConsole = GetConsoleWindow();
	//GetConsoleWindow: retrieves the Window handle used by the console associated with the calling process 

	LONG style = GetWindowLong(myConsole, GWL_STYLE);
	//GetWindowLong: retrieves information about the specified window
	//GWL_STYLE: set a new window style

	style = style  & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME); /*& ~(WS_THICKFRAME);*/ //might use later
	//WS_BORDER: window has a thin-line border => &~(WS_BORDER) will remove it
	//WS_MAXIMIZE: window has a maximize button => ...
	//WS_THICKFRAME: window has a sizing border => ...

	SetWindowLong(myConsole, GWL_STYLE, style);
	//change the attribute of the specified Window
}

void Console::gotoXY(int x, int y)
{
	COORD coordinate; //'COORD': defines the coordinates of a character cell in a console screen buffer.
					 //the origin of the coordinate system (0,0) is at the top, left cell of the buffer.
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
	//SetConsoleCursorPosition(handle, COORD structure): set the cursor position in the specified console screen buffer
	//GetStdHandle(the standard device): retrieves a handle to the specified standard device (st.I/O/Error) 
	//STD_OUTPUT_HANDLE: the standard output device. Initially, this is the active console screen buffer, CONOUT$.
	//note: inside the brackets in the comments are usually the parameters of the function.
}

void Console::setConsoleWindow(int width, int height) //adjust the size of the console window (using MoveWindow)
{
	HWND console = GetConsoleWindow(); //'HWND': window handle
	RECT r; //a 'RECT' structure defines a rectangle by the coordinates of its upper-left and lower right corners.
	GetWindowRect(console, &r);
	//GetWindowRect([in-hWnd]handle to the window, [out-lpRect]pointer to a Rect structure)
	//'GetWindowRect': retrieves the dimensions of the bounding rectangle of the specified Window.
	//The dimensions are given in the screen coordinates that are relative to the upper-left (top-left) conner of the screen

	MoveWindow(console, r.left, r.top, width, height, TRUE);
	//Parameters of MoveWindow:
	/*BOOL MoveWindow(
		[in] HWND hWnd, //handle
		[in] int  X,	//int (new position of the left side of the window)
		[in] int  Y,	//int (new position of the top of the window)
		[in] int  nWidth,	//new width
		[in] int  nHeight,	//new height
		[in] BOOL bRepaint	//bool, indicates whether the window is to be repainted
	);*/
	//Changes the position and dimensions of the specified window.
	//top-level window: the position and dimensions are relative to the upper-left conner of the screen.
	//child-level window: upper-left conner of the parent window's client area.
}

Console::Console()
{
}

Console::~Console()
{
}
