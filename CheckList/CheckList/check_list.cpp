#include "check_list.h"


CheckList::CheckList(const int count, COORD pos, COORD dim) : TextBox(pos,dim) {
	setItemsCount(count);
}

void
CheckList::setItemsCount(const int count) {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

}

void
CheckList::draw() {
	TextBox::draw();
	drawList();
}

void
CheckList::drawList() {


}

void
CheckList::handleInput() {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	INPUT_RECORD record;
	DWORD read_bytes, fdw_mode;
	CONSOLE_SCREEN_BUFFER_INFO info;

	fdw_mode = ENABLE_WINDOW_INPUT | ENABLE_EXTENDED_FLAGS;
	//	fdw_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;

	ReadConsoleInput(_in, &record, 1, &read_bytes);
	SetConsoleMode(_in, fdw_mode);


	switch (record.EventType) {
	case MOUSE_EVENT:
		//TODO: implement mouse event
	case KEY_EVENT:
		GetConsoleScreenBufferInfo(_in, &info);
		if (record.Event.KeyEvent.bKeyDown) {

			if (record.Event.KeyEvent.uChar.AsciiChar == BACKSPACE) {
				if (GetConsoleCursorPosition(_out).X - 1 == _coord.X) {
					if (GetConsoleCursorPosition(_out).Y - 1 > _coord.Y) {
						SetConsoleCursorPosition(_out, { _coord.X + _dim.X - BORDER_OFFSET ,GetConsoleCursorPosition(_out).Y - ((short)1) });
					}
					else {
						break;
					}
				}
				else {
					cout << BACKSPACE << CHAR_RESET;
					SetConsoleCursorPosition(_out, { GetConsoleCursorPosition(_out).X - 1 ,GetConsoleCursorPosition(_out).Y });
				}
			}

			else if (GetConsoleCursorPosition(_out).X + 1 == _dim.X + _coord.X) {
				if (GetConsoleCursorPosition(_out).Y < _dim.Y + _coord.Y) {
					SetConsoleCursorPosition(_out, { _coord.X + 1,GetConsoleCursorPosition(_out).Y + ((short)1) });
				}
			}
			else {
				cout << record.Event.KeyEvent.uChar.AsciiChar;
			}
		}
		break;
	}
}