#include "pg_panel.h"



PgPanel::PgPanel() {
	setBackground(DEF_PANEL_COLOR);
}


PgPanel::~PgPanel()
{
}

void
PgPanel::draw() {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);

	if (_visible) {
		PgComposite::drawBorder();
		drawChildren();
	}
}