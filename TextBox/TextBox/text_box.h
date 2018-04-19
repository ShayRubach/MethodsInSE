#ifndef TEXT_BOX_H
#define TEXT_BOX_H
#include <windows.h>
#include <iostream>
#include <fstream>

#define BORDER_OFFSET (1)
#define TOP_LEFT_CORNER '\xDA'
#define TOP_RIGHT_CORNER '\xBF'
#define BTM_LEFT_CORNER '\xC0'
#define BTM_RIGHT_CORNER '\xD9'
#define LINE_VERTICAL '\xB3'
#define LINE_HORIZONTAL '\xC4'
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
private:
	CONSOLE_SCREEN_BUFFER_INFO _cursor;
	COORD _coord, _dim;
	HANDLE _in, _out;

public:
	TextBox(COORD,COORD);
	~TextBox() {}

	void setBackground(DWORD);
	void draw();
	void innerDraw(char, char, char);
	void handleInput();

};

void printKickAssTitle();

#endif // !TEXT_BOX_H