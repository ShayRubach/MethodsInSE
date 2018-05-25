#include "PgUtils.h"


const char* dbgToString(PgDebugLevel lvl) {
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
