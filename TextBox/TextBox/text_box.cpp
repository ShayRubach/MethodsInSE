#include "text_box.h"

//TODO: make this function as util on a different module. make this receive ... parameters.
void
debug(DebugLevel lvl, char* fn, char* error_msg) {
	#ifndef DEBUG_NONE
		fstream fs;
		fs.open("debug.txt", std::fstream::out | std::fstream::app);
		cout << fn << ": " << error_msg << endl;
	#endif // DEBUG_NONE
}

static COORD
GetConsoleCursorPosition(HANDLE h_out) {
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(h_out, &cbsi)) {
		return cbsi.dwCursorPosition;
	}
	else {
		// The function failed. Call GetLastError() for details.
		return {0, 0};
	}
}

TextBox::TextBox(COORD dim, COORD coord) : _dim(dim), _coord(coord) {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	_in = GetStdHandle(STD_INPUT_HANDLE);
	_out = GetStdHandle(STD_OUTPUT_HANDLE);

	if (_in == INVALID_HANDLE_VALUE || _out == INVALID_HANDLE_VALUE) {
		debug(DBG_ERROR, fn, "one of i/o handles is invalid.");
	}
}

//draw the entire text box
void 
TextBox::draw() {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	SetConsoleCursorPosition(_out, _coord);

	innerDraw(TOP_LEFT_CORNER, LINE_HORIZONTAL, TOP_RIGHT_CORNER);
	SetConsoleCursorPosition(_out, { _coord.X,_coord.Y + 1 });

	for (size_t i = 0; i < _dim.Y ; i++) {
		innerDraw(LINE_VERTICAL, SPACE, LINE_VERTICAL);
		SetConsoleCursorPosition(_out, { _coord.X,_coord.Y + 2 + ((short)i) });
	}

	innerDraw(BTM_LEFT_CORNER, LINE_HORIZONTAL, BTM_RIGHT_CORNER);
	SetConsoleCursorPosition(_out, { _coord.X+1,_coord.Y+1 });
}

// draw a single line by open,mid,close symbols:
void
TextBox::innerDraw(char open_sym, char mid_sym, char close_sym) {
	char* fn = __FUNCTION__;
	debug(DBG_INFO, fn, "called.");

	for (size_t i = 0; i < _dim.X - 1; i++) {
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
							SetConsoleCursorPosition(_out, { _coord.X + _dim.X-BORDER_OFFSET ,GetConsoleCursorPosition(_out).Y - ((short)1) });
						}
						else {
							break;
						}
					}
					else {
						cout << BACKSPACE << CHAR_RESET;
						SetConsoleCursorPosition(_out, { GetConsoleCursorPosition(_out).X-1 ,GetConsoleCursorPosition(_out).Y});
					}
				}

				else if (GetConsoleCursorPosition(_out).X+1 == _dim.X + _coord.X) {
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

void
TextBox::setBackground(DWORD bg) {
	SetConsoleTextAttribute(_out, bg);
}

void
printKickAssTitle() {
	cout << "\t                                     _                      " << endl;
	cout << "\t    _                       _       | |                     " << endl;
	cout << "\t  _| |_  ______   _   _   _| |_     | |__    ___     _   _  " << endl;
	cout << "\t (_   _) | ___ | ( \\ / ) (_   _)    |  _ \\  /  _ \\  ( \\ / ) " << endl;
	cout << "\t   | |_  | ____|  ) X (    | |_     | |_) ) | |_| |  ) X (  " << endl;
	cout << "\t    \\__) |_____) (_/ \\_)    \\__)    |____/  \\____ / (_/ \\_) " << endl;
}