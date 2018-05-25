#pragma once
#include "pg_composite.h"
#ifndef PG_LABEL_H
#define PG_LABEL_H

class PgLabel : public PgComposite
{
public:
	
	PgLabel();
	~PgLabel();

	void draw() {}
};


#endif //PG_LABEL_H