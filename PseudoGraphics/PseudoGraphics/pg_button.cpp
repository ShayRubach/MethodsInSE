#include "pg_button.h"


PgButton::PgButton(PgLabel* label) {
	if (label) {
		add(label);
	}
}

void
PgButton::setButtonName(const string& btn_name) {
	if (!btn_name.empty()) {
		_btn_name = btn_name;
		PgComposite* label = new PgLabel();
		label->setBasePosition({ 0,0 });
		label->setDimensions(getDimensions());
		label->setClickable(true);
		label->setTabbable(true);
		label->setVisible(true);
		static_cast<PgLabel*>(label)->setContent(_btn_name);
		add(label);
	}
}

string PgButton::getButtonName() {
	return _btn_name;
}

void
PgButton::draw() {

	if (_visible) {
		PgComposite::drawBorder();
		drawChildren();
	}

}