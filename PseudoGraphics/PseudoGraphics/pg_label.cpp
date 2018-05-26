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

}

void
PgLabel::setContent(const string& content) {
	const char* fn = __FUNCTION__;

	if (!content.empty()) {
		_content = content;
	}
	else {
		debug(PG_DBG_ERROR, "%s: content string is empty.\n", fn);
	}
	
}

string
PgLabel::getContent() {
	return _content;
}

