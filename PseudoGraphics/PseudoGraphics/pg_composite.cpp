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
	file.open("debug.txt");
	char buffer[512] = {0};


	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	
	file << "[" << dbgToString(lvl) << "] " << buffer;
	va_end(args);
	file.close();
}

//init member variables with def values
PgComposite::PgComposite() : 
	_tabbable(false), _clickable(false), _visible(true),
	_dim({DIM_DEF_W,DIM_DEF_H}), _base_pos({POS_DEF_X,POS_DEF_X }),
	_frame_type(SINGLE_SOLID) {
	
	const char* fn = __FUNCTION__;
	if (_in == INVALID_HANDLE_VALUE || _out == INVALID_HANDLE_VALUE) {
		debug(PG_DBG_ERROR, "one of i/o handles is invalid.", fn);
	}
	
}

void
PgComposite::drawBorder() {

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
PgComposite::drawLine(char open_sym, char mid_sym, char end_sym) {

}

void
PgComposite::add(PgComponent* new_child) {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.\n", fn);
	debug(PG_DBG_INFO, "%s: new_child=%d.\n", fn, new_child);

	if (new_child) {
		children.push_back(new_child);
	}
	else {
			debug(PG_DBG_INFO, "%s: new_child is null.", fn);
	}
}

void
PgComposite::remove(const int pos) {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.\n", fn);
	debug(PG_DBG_INFO, "%s: pos=%d.\n", fn, pos);
	
}

PgComponent* 
PgComposite::getChild(const int pos) {
	if (isValidPos(children.size(), pos)) {
		return children.at(pos);
	}
	return NULL;
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
