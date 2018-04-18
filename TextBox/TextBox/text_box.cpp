#include "text_box.h"

TextBox::TextBox(HANDLE _handle, COORD _coord) : handle(_handle),coord(_coord) {
	//char* fn = "TextBox::TextBox";
	//cout << fn << ": called." << endl;
}


TextBox::~TextBox() {
}

void TextBox::draw() {

}

void TextBox::setBackground(DWORD bg) {
	SetConsoleTextAttribute(handle, bg);
}