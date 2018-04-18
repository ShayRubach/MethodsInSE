#ifndef TEXT_BOX_H
#define TEXT_BOX_H
#include <windows.h>
#include <iostream>

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
	~TextBox();

	void setBackground(DWORD);
	void draw();
	
	COORD getCoord()			const { return coord; }
	Dimension getDim()		const { return dim; }
	HANDLE getInHandle()	const { return in; }
	HANDLE getOutHandle()	const { return out; }

};

#endif // !TEXT_BOX_H