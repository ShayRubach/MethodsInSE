#ifndef TEXT_BOX_H
#define TEXT_BOX_H
#include <windows.h>
#include <iostream>
#include <fstream>

#define BORDER_OFFSET (1)
#define TOP_LEFT_CORNER '\xC9'
#define TOP_RIGHT_CORNER '\xBB'
#define BTM_LEFT_CORNER '\xC8'
#define BTM_RIGHT_CORNER '\xBC'
#define LINE_VERTICAL '\xBA'
#define LINE_HORIZONTAL '\xCD'
#define BACKSPACE '\x08'
#define SPACE '\x20'
#define CHAR_RESET '\x0'

//comment to turn on debug:
#define DEBUG_NONE

using namespace std;

typedef enum {
	DBG_INFO = 0,
	DBG_ERROR,
}DebugLevel;

class TextBox {
protected:
	CONSOLE_SCREEN_BUFFER_INFO _cursor;
	COORD _coord, _dim;
	HANDLE _in, _out;

public:
	TextBox(COORD coord = {0,0}, COORD dim = { 0,0 });
	~TextBox() {}

	void setBackground(DWORD);
	void draw();
	void innerDraw(char, char, char);
	void handleInput();

};

void debug(DebugLevel, char*, char*);
COORD GetConsoleCursorPosition(HANDLE h_out);
void printKickAssTitle();

#endif // !TEXT_BOX_H