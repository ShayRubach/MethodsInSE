#include "pg_components_factory.h"

#define APP_RGB (90|10|30)
#define ITEMS_COUNT (8)
#define TB_HEIGHT	(10)
#define TB_WIDTH	(60)
#define SCREEN_POS_X (10)
#define SCREEN_POS_Y (10)


int main() {

	PgComposite* label = PgComponentsFactory::getInstance().create(LABEL);
	PgComposite* button = PgComponentsFactory::getInstance().create(BUTTON);

	label->setFrameType(DOUBLE_SOLID);
	label->draw();

	while (true) {

	}

	return 1;
}