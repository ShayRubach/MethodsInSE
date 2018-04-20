#include "check_list.h"

#define APP_RGB (90|10|30)
#define ITEMS_COUNT (8)
#define TB_HEIGHT	(10)
#define TB_WIDTH	(60)
#define SCREEN_POS_X (10)
#define SCREEN_POS_Y (10)


int main() {

	COORD cl_dim = { TB_WIDTH, TB_HEIGHT };
	COORD cl_pos = { SCREEN_POS_X, SCREEN_POS_Y };

	CheckList check_list(ITEMS_COUNT, cl_dim, cl_pos);
	check_list.setBackground(APP_RGB);
	check_list.draw();

	while (true) {
		check_list.handleInput();
	}

	return 1;
}