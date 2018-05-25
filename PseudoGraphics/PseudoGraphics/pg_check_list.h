#pragma once
#include "pg_list.h"
class PgCheckList : public PgList
{
public:
	PgCheckList();
	~PgCheckList();

	void draw() {}
	bool onKeyPressed() { return true; }
	bool onClick() { return true; }
	bool onHover() { return true; }
	void chooseLine() {}

	string& getSelectedItem();							//override
	vector<bool>& getSelectedPositions();		//new method
};

