#pragma once
#ifndef PG_PANEL_H
#define PG_PANEL_H
#include "pg_composite.h"

class PgPanel : public PgComposite
{
public:
	PgPanel();
	~PgPanel();

	void draw() {}
};

#endif //PG_PANEL_H