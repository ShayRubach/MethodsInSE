#ifndef CHECK_LIST_H
#define CHECK_LIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include "text_box.h"

//comment out to remove title print
#define PRINT_TITLE (1)

#define SYM_BULLET "( )"
#define SYM_MARKER "<---"
#define SYM_SPACE ' '
#define SYM_CLEAR  "    "
#define SYM_CHOICE '*'
#define SYM_CHOICE_OFFSET (3)
#define PROMPT_OFFSET (36)


class CheckList : public TextBox
{

private:
	int _items_cnt;
	std::vector<bool> _choices;

public:
	CheckList(const int count, COORD dim = { 10,10 }, COORD pos = { 10,50 });
	~CheckList();

	void setItemsCount(const int count);
	void handleInput();
	void draw();
	void innerDraw(char* open_sym, char* text, size_t line_num);
	void chooseLine();
	void setLineMarker(char* symbol);
	void printKickAssTitle();
};

#endif // !CHECK_LIST_H