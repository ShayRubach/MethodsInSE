#include "pg_composite.h"

//init static handles (shared among all components - prohibit multiple handlers):
HANDLE PgComposite::_in = GetStdHandle(STD_INPUT_HANDLE);
HANDLE PgComposite::_out = GetStdHandle(STD_OUTPUT_HANDLE);

static bool 
isValidPos(const int &size, const int &pos) {
	if (pos < 0 || pos > size) {
		return false;
	}
	return true;

}

static const char* 
dbgToString(PgDebugLevel lvl) {
	switch (lvl)
	{
	case PG_DBG_INFO:
		return PG_INFO;
	case PG_DBG_ERROR:
		return PG_ERR;
	default:
		return PG_STANDARD;
	}
}

void
debug(PgDebugLevel lvl, const char *format, ...) {
	ofstream file;
	time_t now = time(0);
	tm *ltm = localtime(&now);

	file.open(DBG_FILE_NAME, std::ios_base::app);
	char buffer[512] = {0};


	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	
	file << "{" << ltm->tm_hour << ":";
	file << ltm->tm_min << ":";
	file << ltm->tm_sec << "}";
	file << " [" << dbgToString(lvl) << "] " << buffer << "\n";
	va_end(args);
	file.close();
}

//init member variables with def values
PgComposite::PgComposite() : 
	_tabbable(false), _clickable(false), _visible(true),
	_dim({DIM_DEF_W,DIM_DEF_H}), _base_pos({POS_DEF_X,POS_DEF_X }),
	_frame_type(SINGLE_SOLID) {
	
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);

	if (_in == INVALID_HANDLE_VALUE || _out == INVALID_HANDLE_VALUE) {
		debug(PG_DBG_ERROR, "%s: one of i/o handles is invalid.", fn);
	}
	
}

void
PgComposite::drawBorder() {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);

	char top_left, top_right, btm_left, btm_right;
	char line_horiz, line_vert;

	//reset our cursor pos to base pos
	SetConsoleCursorPosition(_out, _base_pos);

	if (_frame_type == NONE) {
		for (int i = 0; i < this->_dim.X; ++i) {
			//draw empty lines as border
			drawLine(SPACE, SPACE, SPACE);
			SetConsoleCursorPosition(_out, { _base_pos.X,_base_pos.Y +	(short)i });
		}
		return;
	}

	//handle the single | double scenario:
	top_left   = (_frame_type == SINGLE_SOLID ? SINGLE_TOP_LEFT_CORNER  : DOUBLE_TOP_LEFT_CORNER );
	top_right  = (_frame_type == SINGLE_SOLID ? SINGLE_TOP_RIGHT_CORNER : DOUBLE_TOP_RIGHT_CORNER);
	btm_left   = (_frame_type == SINGLE_SOLID ? SINGLE_BTM_LEFT_CORNER  : DOUBLE_BTM_LEFT_CORNER);
	btm_right  = (_frame_type == SINGLE_SOLID ? SINGLE_BTM_RIGHT_CORNER : DOUBLE_BTM_RIGHT_CORNER);
	line_horiz = (_frame_type == SINGLE_SOLID ? SINGLE_LINE_HORIZONTAL  : DOUBLE_LINE_HORIZONTAL);
	line_vert  = (_frame_type == SINGLE_SOLID ? SINGLE_LINE_VERTICAL    : DOUBLE_LINE_VERTICAL);

	
	drawLine(top_left, line_horiz, top_right);
	SetConsoleCursorPosition(_out, { _base_pos.X,_base_pos.Y + 1 });

	for (size_t i = 0; i < _dim.Y; i++) {
		drawLine(line_vert, SPACE, line_vert);
		SetConsoleCursorPosition(_out, { _base_pos.X,_base_pos.Y + 2 + ((short)i) });
	}

		drawLine(btm_left, line_horiz, btm_right);
		SetConsoleCursorPosition(_out, { _base_pos.X + 1,_base_pos.Y + 1 });
	

	//reset our cursor pos to base pos again
	SetConsoleCursorPosition(_out, _base_pos);
}

void
PgComposite::drawChildren() {
	for each (PgComponent* child in children) {
		child->draw();
	}
}

void
PgComposite::drawLine(char open_sym, char mid_sym, char end_sym) {
	char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);

	for (size_t i = 0; i < _dim.X - 1; i++) {
		if (i == 0) {
			cout << open_sym;
		}
		else {
			cout << mid_sym;
		}
	}
	cout << end_sym;
}

void
PgComposite::add(PgComponent* new_child, bool tabbable, bool clickable) {
	static_cast<PgComposite*>(new_child)->setTabbable(tabbable);
	static_cast<PgComposite*>(new_child)->setClickable(clickable);
	add(new_child);
}

void
PgComposite::add(PgComponent* new_child) {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);
	debug(PG_DBG_INFO, "%s: new_child=%d.", fn, new_child);

	if (new_child) {

		//fix child position in relation to this parent:
		//we need to cast to Compsite in order to access the getter.
		short new_pos_x = _base_pos.X + static_cast<PgComposite*>(new_child)->_base_pos.X;
		short new_pos_y = _base_pos.Y + static_cast<PgComposite*>(new_child)->_base_pos.Y;
		static_cast<PgComposite*>(new_child)->setBasePosition({ new_pos_x, new_pos_y });
	
		children.push_back(new_child);
	}
	else {
			debug(PG_DBG_INFO, "%s: new_child is null.", fn);
	}
	
}

void
PgComposite::remove(const int pos) {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);
	debug(PG_DBG_INFO, "%s: pos=%d.", fn, pos);
	
}

PgComponent* 
PgComposite::getChild(const int pos) {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);

	if (isValidPos(children.size(), pos)) {
		return children.at(pos);
	}
	return NULL;
}

COORD
PgComposite::GetConsoleCursorPosition(HANDLE h_out) {
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(h_out, &cbsi)) {
		return cbsi.dwCursorPosition;
	}
	else {
		// The function failed. Call GetLastError() for details.
		return{ 0, 0 };
	}
}

PgComposite::~PgComposite() {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);
	for each (PgComponent* child in children) {
		if (child) {
			delete child;
		}
	}
}


vector<PgComponent*> 
PgComposite::getChildren() {
	return children;
}

COORD 
PgComposite::getDimensions() {
	return _dim;
}

COORD 
PgComposite::getBasePosition() {
	return _base_pos;
}

PgFrameType 
PgComposite::getFrameType() {
	return _frame_type;
}

bool
PgComposite::isTabbable() {
	return _tabbable;
}

bool
PgComposite::isClickable() {
	return _clickable;
}

bool
PgComposite::isVisible() {
	return _visible;
}

void 
PgComposite::setTabbable(bool tabbable) {
	_tabbable = tabbable;
}

void
PgComposite::setVisible(bool visible) {
	_visible = visible;
}

void
PgComposite::setClickable(bool clickable) {
	_clickable = clickable;
}

void
PgComposite::setFrameType(PgFrameType frame_type) {
	_frame_type = frame_type;
}

void
PgComposite::setDimensions(COORD dim) {
	_dim = dim;
}

void
PgComposite::setBasePosition(COORD pos) {
	_base_pos = pos;
}

DWORD
PgComposite::getBackgroundColor() {
	return _bg_color;
}

void 
PgComposite::setBackground(DWORD bg) {
	_bg_color = bg;
	SetConsoleTextAttribute(_out, bg);
}
