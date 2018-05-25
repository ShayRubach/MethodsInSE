#pragma once
#include "pg_label.h"
#ifndef PG_TEXTBOX_H
#define PG_TEXTBOX_H

class PgTextBox : public PgComposite
{
public:
	PgTextBox();
	~PgTextBox();

	void draw() {}
};

#endif // !PG_TEXTBOX_H
