#pragma once
#ifndef PG_BUTTON_H
#define PG_BUTTON_H
#include "pg_label.h"

class PgButton : public PgComposite
{
	string _btn_name;

public:
	PgButton() = default;
	PgButton(PgLabel* label);
	~PgButton() = default;
	void setButtonName(const string& btn_name);
	string getButtonName();


	void draw();
};

#endif // !PG_BUTTON_H
