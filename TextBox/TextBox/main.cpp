#include "text_box.h"

#define RGB (50|1|30)
#define TB_HEIGHT	(4)
#define TB_WIDTH	(25)
#define SCREEN_POS_X (30)
#define SCREEN_POS_Y (10)



int main() {
	
	COORD tb_dim = {TB_WIDTH, TB_HEIGHT};
	COORD tb_pos = {SCREEN_POS_X, SCREEN_POS_Y};
									
	TextBox text_box(tb_dim, tb_pos);
	printKickAssTitle();
	text_box.setBackground(RGB);
	text_box.draw();

	while (true) {
		text_box.handleInput();
	}

	return 1;
}

