#ifndef CHECK_LIST_H
#define CHECK_LIST_H

#include <iostream>
#include <fstream>
#include "text_box.h"

#define SYM_BULLET "( )"
#define SYM_MARKER "<---"
#define SYM_CLEAR  "    "
#define SYM_CHOICE 'X'
#define PROMPT_OFFSET (36)


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
	void innerDraw(char* open_sym, char* text, size_t line_num);
	void chooseLine(size_t line_num);
	void setLineMarker(char* symbol);

};

#endif // !CHECK_LIST_H