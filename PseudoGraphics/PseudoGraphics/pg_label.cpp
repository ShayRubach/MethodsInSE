#include "pg_label.h"


PgLabel::~PgLabel()
{
}

PgLabel::PgLabel(COORD pos, COORD dim, const string& content) : PgComposite() {
	setBasePosition(pos);
	setDimensions(dim);
	setContent(content);
}

void
PgLabel::draw() {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);

	drawBorder();

}

void
PgLabel::setContent(const string& content) {
	const char* fn = __FUNCTION__;

	if (!content.empty()) {
		_content = content;
	}
	else {
		debug(PG_DBG_INFO, "%s: content string is empty.\n", fn);
	}
	
}

string
PgLabel::getContent() {
	return _content;
}

