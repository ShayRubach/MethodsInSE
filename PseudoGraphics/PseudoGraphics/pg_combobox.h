#pragma once
#ifndef PG_COMBOBOX_H
#define PG_COMBOBOX_H

#include "pg_list.h"
class PgComboBox : public PgList
{
public:
	PgComboBox();
	~PgComboBox();

	void draw() {}
	bool onKeyPressed() { return true; }
	bool onClick() { return true; }
	bool onHover() { return true; }
	void chooseLine() {}
};

#endif // !PG_COMBOBOX_H
