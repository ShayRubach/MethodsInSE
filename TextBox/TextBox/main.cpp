#include "text_box.h"

#define RGB (50|1|30)
#define TB_HEIGHT				(10)
#define TB_WIDTH				(20)
#define SCREEN_POS_X		(20)
#define SCREEN_POS_Y		(10)

int main() {
	
	Dimension tb_border = {TB_HEIGHT, TB_WIDTH};
	COORD tb_pos = {SCREEN_POS_X, SCREEN_POS_Y};
									
	TextBox text_box(tb_border,tb_pos);
	text_box.setBackground(RGB);
	text_box.draw();




	return 1;
}