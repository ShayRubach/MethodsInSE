#pragma once
#include "pg_composite.h"
#ifndef PG_LABEL_H
#define PG_LABEL_H

class PgLabel : public PgComposite
{
	string _content;

public:
	
	PgLabel() = default;
	PgLabel(COORD pos, COORD dim, const string& content);
	~PgLabel();

	void draw();
	void drawContent(string& _content);
	void setContent(const string& content);
	string getContent();
};


#endif //PG_LABEL_H