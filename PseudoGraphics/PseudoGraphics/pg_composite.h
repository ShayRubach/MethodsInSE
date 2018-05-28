#pragma once
#ifndef PG_COMPOSITE_H
#define PG_COMPOSITE_H

#include "pg_component.h"
#include "pg_constants.h"
#include <fstream>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <memory>

#define PG_INFO			"INFO";
#define PG_ERR			"ERROR";
#define PG_STANDARD	"DBG";

using namespace std;

typedef enum  {
	PG_DBG_INFO,
	PG_DBG_ERROR
}PgDebugLevel;

typedef enum {
	NONE,
	SINGLE_SOLID,
	DOUBLE_SOLID
}PgFrameType;

class PgComposite : public PgComponent
{

protected:
	bool _tabbable;
	bool _clickable;
	bool _visible;
	COORD _dim;
	COORD _base_pos;
	DWORD _bg_color;
	PgFrameType _frame_type;
	vector<PgComponent*> children;
	HANDLE _in, _out;
	CONSOLE_CURSOR_INFO _cursor_info;

public:
	PgComposite();
	virtual ~PgComposite();

	virtual void draw() = 0;
	virtual void drawBorder();
	virtual void drawChildren();
	virtual void drawLine(char, char, char);
	virtual void handleInput() {};
	
	void add(PgComponent*);
	void add(PgComponent*,bool,bool);

	void remove(const int pos);
	PgComponent* getChild(const int pos);
	vector<PgComponent*> getChildren();
	COORD getDimensions();
	COORD getBasePosition();
	COORD GetConsoleCursorPosition(HANDLE h_out);
	DWORD getBackgroundColor();
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
	void setBackground(DWORD);
	void setCursorAttributes(DWORD size, BOOL visible);
	
};

void debug(PgDebugLevel lvl, const char *format, ...);

#endif // !PG_COMPOSITE_H
