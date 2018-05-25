#pragma once
#ifndef PG_NUMERICBOX_H
#define PG_NUMERICBOX_H
#include "pg_label.h"
#include "pg_button.h"


class PgNumericBox : public PgComposite
{
public:
	PgNumericBox();
	~PgNumericBox();

	void draw() {}
};

#endif //PG_NUMERICBOX_H