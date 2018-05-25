#include "PgComposite.h"

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