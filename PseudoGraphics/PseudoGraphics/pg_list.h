#pragma once
#ifndef PG_LIST_H
#define PG_LIST_H

#include "pg_label.h"
#include "mouse_listener.h"
#include "keyboard_listener.h"

class PgList : public PgComposite, IKeyboardListener, IMouseListener
{
	vector<PgLabel> _items;
	vector<bool> _selected_pos;

public:
	PgList();
	virtual ~PgList();
	virtual void draw() = 0;
	virtual bool onKeyPressed() = 0;
	virtual bool onClick() = 0;
	virtual bool onHover()= 0;
	virtual void chooseLine() = 0;
		
	bool addItem(const string&);
	bool addItemAt(const int&, const string&);
	bool removeItem(const string&);
	bool removeItemAt(const int&);
	bool removeSelectedItem();
	bool isEmpty();
	bool clean();
	void invertLineColor(const int&);
	void setItemList(vector<string>&);
	int getSelectedPos(); 
	vector<string>& getItemList();
	string& getItemAt(const int&);
	string& getSelectedItem();
};

#endif // !PG_LIST_H
