#ifndef CHECK_LIST_H
#define CHECK_LIST_H

#include <iostream>
#include <fstream>
#include "text_box.h"


class CheckList : public TextBox
{

private:
	int _items_cnt;

public:
	CheckList(const int count, COORD dim = { 10,10 }, COORD pos = { 10,50 });
	~CheckList() {}

	void setItemsCount(const int count);
	void handleInput();
	void draw();
	void drawList();

};

#endif // !CHECK_LIST_H