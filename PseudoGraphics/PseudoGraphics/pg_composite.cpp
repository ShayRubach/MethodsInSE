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

	cout << "[" << dbgToString(lvl) << "] ";

	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

PgComposite::PgComposite() {
	const char* fn = __FUNCTION__;
	if (_in == INVALID_HANDLE_VALUE || _out == INVALID_HANDLE_VALUE) {
		debug(PG_DBG_ERROR, "one of i/o handles is invalid.", fn);
	}
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
