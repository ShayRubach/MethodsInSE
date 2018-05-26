#include "pg_label.h"


PgLabel::~PgLabel() {
	const char* fn = __FUNCTION__;
	debug(PG_DBG_INFO, "%s: called.", fn);
	PgComposite::~PgComposite();
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

	if (_visible) {
		PgComposite::drawBorder();
		drawContent(_content);
	}
}


void
PgLabel::drawContent(string& content) {
	const char* fn = __FUNCTION__;
	//set cursor at starting point, within frame borders:
	SetConsoleCursorPosition(_out, { _base_pos.X+1,_base_pos.Y + 1 });

	//write content inside
	for (size_t i = 0; i < content.length() ; i++) {
		//if we reached the maximum line width
		if (GetConsoleCursorPosition(_out).X == _base_pos.X +_dim.X - 1) {
			if (GetConsoleCursorPosition(_out).Y == _base_pos.Y + _dim.Y - 1) {
				debug(PG_DBG_INFO, "%s: can't write any more content. no space left in this frame.", fn);
				return;
			}
			else {
				//go down 1 line:
				SetConsoleCursorPosition(_out, { _base_pos.X+1 ,GetConsoleCursorPosition(_out).Y + ((short)1) });
			}
		}
		//draw our character
		cout << content.at(i);
	}
}

void
PgLabel::setContent(const string& content) {
	const char* fn = __FUNCTION__;

	if (!content.empty()) {
		_content = content;
	}
	else {
		debug(PG_DBG_INFO, "%s: content string is empty.", fn);
	}	
}

string
PgLabel::getContent() {
	return _content;
}


