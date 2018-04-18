#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <windows.h>
#include <iostream>

using namespace std;

class TextBox
{
private:
	COORD coord;
	HANDLE handle;
	short int len;

public:
	TextBox(HANDLE,COORD);
	~TextBox();

	void setBackground(DWORD);
	void draw();

};

#endif // !TEXT_BOX_H