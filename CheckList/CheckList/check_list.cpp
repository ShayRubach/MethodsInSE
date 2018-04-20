#include "check_list.h"


CheckList::CheckList(const int count, COORD pos, COORD dim) : TextBox(pos, dim) {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called."); 
	
	setItemsCount(count);
	_choices.resize(_items_cnt);
}

CheckList::~CheckList() {}

void
CheckList::setItemsCount(const int count) {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	_items_cnt = count > _dim.Y ? _dim.Y : count ;
}

void
CheckList::draw() {
	TextBox::draw();
	for (size_t i = 0; i < _items_cnt; i++) {
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
CheckList::chooseLine() {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	//update bitset:
	int line_num = GetConsoleCursorPosition(_out).Y - _dim.Y - 1;
	_choices.at(line_num) = _choices.at(line_num) ^ 1;

	SetConsoleCursorPosition(_out, { _coord.X + SYM_CHOICE_OFFSET, GetConsoleCursorPosition(_out).Y });

	if (_choices.at(line_num)) {
		cout << SYM_CHOICE;
	}
	else {
		cout << SYM_SPACE;
	}
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

			//if the up/down/space key has been pressed (keep in borders):
			if ((GetKeyState(VK_UP) & 0x8000 ) && curr_pos.Y > _coord.Y+1) {
				SetConsoleCursorPosition(_out, { curr_pos.X, curr_pos.Y - 1 });
			}
			else if ((GetKeyState(VK_DOWN) & 0x8000) && curr_pos.Y < _coord.Y + _items_cnt) {
				SetConsoleCursorPosition(_out, { curr_pos.X, curr_pos.Y + 1 });
			} 
			else if (GetKeyState(VK_SPACE) & 0x8000) {
				chooseLine();
			}
			setLineMarker(SYM_MARKER);
		}
		break;
	}
}

void
CheckList::setLineMarker(char* symbol) {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	SetConsoleCursorPosition(_out, { _coord.X + _dim.X-PROMPT_OFFSET,GetConsoleCursorPosition(_out).Y });
	cout << symbol;
	
}

void
CheckList::printKickAssTitle() {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

#ifdef PRINT_TITLE
	//			-------------c-----------     ------------h--------------   ------------e---------------  --------------c------------   ---------------k-----------         ------------------L----------    ---i---		-----------s--------------   --------------t-------------
	SetConsoleCursorPosition(_out, { 24,2 });
	cout << '\xDA' << '\xC4' << '\xBF' << '\xC2' << ' '    << '\xC2' << '\xDA' << '\xC4' << '\xBF' << '\xDA' << '\xC4' << '\xBF' << '\xC2' << '\xDA' << '\xC4' << "   " << '\xC2' << ' '    << ' '		<< '\xC2' << '\xDA' << '\xC4' << '\xBF' << '\xDA' << '\xC2' << '\xBF';
	SetConsoleCursorPosition(_out, { 24,3 });
	cout << '\xB3' << ' '    << ' '    << '\xC3' << '\xC4' << '\xB4' << '\xC3' << '\xB4' << ' '    << '\xB3' << ' '    << ' '    << '\xC3' << '\xC1' << '\xBF' << "   " << '\xC3' << ' '    << ' '    << '\xB3' << '\xC0' << '\xC4' << '\xBF' << ' '    << '\xB3' << ' '   ;
	SetConsoleCursorPosition(_out, { 24,4 });
	cout << '\xC0' << '\xC4' << '\xD9' << '\xC1' << ' '    << '\xC1' << '\xC0' << '\xC4' << '\xD9' << '\xC0' << '\xC4' << '\xD9' << '\xC1' << ' '    << '\xC1' << "   " << '\xC1' << '\xC4' << '\xD9' << '\xC1' << '\xC0' << '\xC4' << '\xD9' << ' '    << '\xC1' << ' '	 ;
#endif
}
