#include "text_box.h"

TextBox::TextBox(Dimension _dim, COORD _coord) : dim(_dim), coord(_coord) {
	in = GetStdHandle(STD_INPUT_HANDLE);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
}

//draw the entire text box
void 
TextBox::draw() {
	SetConsoleCursorPosition(out, coord);

	innerDraw(TOP_LEFT_CORNER, LINE_HORIZONTAL, TOP_RIGHT_CORNER);
	SetConsoleCursorPosition(out, { coord.X,coord.Y + 1 });

	for (size_t i = 0; i < dim.y ; i++) {
		innerDraw(LINE_VERTICAL, SPACE, LINE_VERTICAL);
		SetConsoleCursorPosition(out, { coord.X,coord.Y + 2 + ((short)i) });
	}

	innerDraw(BTM_LEFT_CORNER, LINE_HORIZONTAL, BTM_RIGHT_CORNER);
	SetConsoleCursorPosition(out, { coord.X+1,coord.Y+1 });
}

// draw a single line by open,mid,close symbols:
void
TextBox::innerDraw(char open_sym, char mid_sym, char close_sym) {
	for (size_t i = 0; i < dim.x - 1; i++) {
		if (i == 0) {
			cout << open_sym;
		}
		else {
			cout << mid_sym;
		}
	}
	cout << close_sym;
}

// keep user input in borders:
void
TextBox::handleInput() {

}

void
TextBox::setBackground(DWORD bg) {
	SetConsoleTextAttribute(out, bg);
}