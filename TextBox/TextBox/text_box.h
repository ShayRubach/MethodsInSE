#ifndef TEXT_BOX_H
#define TEXT_BOX_H
#include <windows.h>
#include <iostream>

#define TOP_LEFT_CORNER '\xDA'
#define TOP_RIGHT_CORNER '\xBF'
#define BTM_LEFT_CORNER '\xC0'
#define BTM_RIGHT_CORNER '\xD9'
#define LINE_VERTICAL '\xB3'
#define LINE_HORIZONTAL '\xC4'
#define SPACE '\x20'

using namespace std;


typedef struct {
	short x;
	short y;
}Dimension;

class TextBox
{
private:
	CONSOLE_SCREEN_BUFFER_INFO cursor;
	COORD coord;
	HANDLE in, out;
	Dimension dim;

public:
	TextBox(Dimension,COORD);
	~TextBox() {}

	void setBackground(DWORD);
	void draw();
	void innerDraw(char, char, char);
	void handleInput();
	
	COORD getCoord()			const { return coord; }
	Dimension getDim()		const { return dim; }
	HANDLE getInHandle()	const { return in; }
	HANDLE getOutHandle()	const { return out; }

};

#endif // !TEXT_BOX_H