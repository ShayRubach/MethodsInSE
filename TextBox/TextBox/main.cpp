#include "text_box.h"
#define BG BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED

int main() {
	
	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO cursor;
	GetConsoleScreenBufferInfo(out, &cursor);
	SetConsoleCursorPosition(out, { 10,20 });

	TextBox text_box(in, { 10,15 });
	text_box.setBackground(BG);
	text_box.draw();




	return 1;
}