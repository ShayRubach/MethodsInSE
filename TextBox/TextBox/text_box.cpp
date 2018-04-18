#include "text_box.h"

TextBox::TextBox(Dimension _dim, COORD _coord) : dim(_dim), coord(_coord) {
	in = GetStdHandle(STD_INPUT_HANDLE);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
}


TextBox::~TextBox() {
}

void TextBox::draw() {

	GetConsoleScreenBufferInfo(out, &cursor);
	SetConsoleCursorPosition(out, coord);

}

void TextBox::setBackground(DWORD bg) {
	SetConsoleTextAttribute(out, bg);
}