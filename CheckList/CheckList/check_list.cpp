#include "check_list.h"


CheckList::CheckList(const int count, COORD pos, COORD dim) : TextBox(pos, dim) {
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
	for (size_t i = 0; i < _dim.Y; i++) {
		innerDraw(SYM_BULLET, "Option no. ", i);
		SetConsoleCursorPosition(_out, { _coord.X + 2,_coord.Y + 2 + ((short)i) });
	}
	SetConsoleCursorPosition(_out, { _coord.X + 2,_coord.Y + 1 });
	setLineMarker(SYM_MARKER);
}

void
CheckList::innerDraw(char* open_sym, char* text, size_t line_num) {
	// draw a single line by open,mid,close symbols:
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	cout << open_sym << " ";
	cout << text << line_num;

}

void
CheckList::chooseLine(size_t line_num) {

}

void
CheckList::handleInput() {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	INPUT_RECORD record;
	DWORD read_bytes, fdw_mode;
	CONSOLE_SCREEN_BUFFER_INFO info;
	COORD curr_pos;

	fdw_mode = ENABLE_WINDOW_INPUT | ENABLE_EXTENDED_FLAGS;

	ReadConsoleInput(_in, &record, 1, &read_bytes);
	SetConsoleMode(_in, fdw_mode);

	switch (record.EventType) {
	case MOUSE_EVENT:
		//TODO: implement mouse event
		break;
	case KEY_EVENT:
		//get screen buffer info:
		GetConsoleScreenBufferInfo(_in, &info);
		//get current cursor position:
		curr_pos.X = GetConsoleCursorPosition(_out).X;
		curr_pos.Y = GetConsoleCursorPosition(_out).Y;

		//handle key event
		if (record.Event.KeyEvent.bKeyDown) {
			//clean the symbol marker (the arrow):
			setLineMarker(SYM_CLEAR);

			//if the up arrow key has been pressed (keep in borders):
			if ((GetKeyState(VK_UP) & 0x8000 ) && curr_pos.Y > _coord.Y+1) {
				SetConsoleCursorPosition(_out, { curr_pos.X, curr_pos.Y - 1 });
			}
			else if ((GetKeyState(VK_DOWN) & 0x8000) && curr_pos.Y < _coord.Y + _dim.Y) {
				SetConsoleCursorPosition(_out, { curr_pos.X, curr_pos.Y + 1 });
			} 
			else if (GetKeyState(VK_SPACE) & 0x8000) {
				chooseLine(SYM_CHOICE);
			}

			setLineMarker(SYM_MARKER);
		}

		break;
	}
}

void
CheckList::setLineMarker(char* symbol) {
	SetConsoleCursorPosition(_out, { _coord.X + _dim.X-PROMPT_OFFSET,GetConsoleCursorPosition(_out).Y });
	cout << symbol;
	
}
