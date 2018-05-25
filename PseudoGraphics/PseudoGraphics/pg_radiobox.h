#pragma once
#ifndef PG_RADIOBOX_H
#define PG_RADIOBOX_H

#include "pg_list.h"
class PgRadioBox : public PgList
{
public:
	PgRadioBox();
	~PgRadioBox();

	void draw() {}
	bool onKeyPressed() { return true; }
	bool onClick() { return true; }
	bool onHover() { return true; }
	void chooseLine() {}
};

#endif // !PG_RADIOBOX_H
