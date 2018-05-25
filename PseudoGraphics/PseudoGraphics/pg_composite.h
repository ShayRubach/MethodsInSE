#pragma once
#ifndef PG_COMPOSITE_H
#define PG_COMPOSITE_H

#include "pg_component.h"
#include <Windows.h>
#include <vector>
#include <iostream>

#define PG_INFO			"INFO";
#define PG_ERR			"ERROR";
#define PG_STANDARD	"DBG";

using namespace std;

enum PgDebugLevel {
	PG_DBG_INFO,
	PG_DBG_ERROR
};

enum PgFrameType {
	NONE,
	SINGLE_SOLID,
	DOUBLE_SOLID
};

class PgComposite : public PgComponent
{
private:
	bool _tabbable;
	bool _clickable;
	bool _visible;
	COORD _dim;
	COORD _base_pos;
	PgFrameType _frame_type;
	vector<PgComponent*> children;


public:
	virtual ~PgComposite() {}

	virtual void draw() = 0;
	virtual void innerDraw() {}
	
	void add(PgComponent*);
	void remove(const int pos);
	PgComponent* getChild(const int pos);
	vector<PgComponent*> getChildren();
	COORD getDimensions();
	COORD getBasePosition();
	PgFrameType getFrameType();
	bool isTabbable();
	bool isClickable();
	bool isVisible();	
	void setTabbable(bool tabbable);
	void setVisible(bool visible);
	void setClickable(bool clickable);
	void setFrameType(PgFrameType frame_type);
	void setDimensions(COORD dim);
	void setBasePosition(COORD pos);
	
};


#endif // !PG_COMPOSITE_H
