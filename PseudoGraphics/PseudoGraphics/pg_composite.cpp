#include "pg_composite.h"

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