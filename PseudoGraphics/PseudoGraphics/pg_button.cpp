#include "pg_button.h"


PgButton::PgButton(PgLabel* label) {
	if (label) {
		add(label);
	}
}

void
PgButton::draw() {

	if (_visible) {
		PgComposite::drawBorder();
		drawChildren();
	}
}