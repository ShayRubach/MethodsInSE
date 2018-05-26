#pragma once
#ifndef PG_BUTTON_H
#define PG_BUTTON_H
#include "pg_label.h"

class PgButton : public PgComposite
{
public:
	PgButton() = default;
	PgButton(PgLabel* label);
	PgButton(const string& label);
	~PgButton() = default;

	void draw();
};

#endif // !PG_BUTTON_H
