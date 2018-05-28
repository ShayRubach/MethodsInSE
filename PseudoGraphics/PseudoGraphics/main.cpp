#include "pg_components_factory.h"

#define APP_RGB (90|10|30)
#define DEBUG_ON		(1)

int main() {
	//create our factory:
	PgComponentsFactory& factory = PgComponentsFactory::getInstance();

	PgComposite* panel = factory.create(PANEL);
	PgComposite* label = factory.create(LABEL);
	
	PgComposite* button = factory.create(BUTTON);

	panel->setFrameType(DOUBLE_SOLID);
	panel->setBackground(50|50|50);
	panel->setDimensions({ 30, 30 });
	panel->setBasePosition({ 1, 1 });
	panel->draw();
	
	//PgLabel example
	label->setFrameType(NONE);
	label->setBackground(APP_RGB);
	label->setDimensions({ 30, 3 });
	label->setBasePosition({ 30, 5 });
	static_cast<PgLabel*>(label)->setContent("I'M PICKLE RIIIIIIIIICK");
	label->draw();

	button->setFrameType(SINGLE_SOLID);
	button->setBackground(100|20|200);
	button->setDimensions({ 10, 3 });
	button->setBasePosition({10,10});
	static_cast<PgButton*>(button)->setButtonName("Click Me");
	button->draw();

	
	if (!DEBUG_ON) {
		remove(DBG_FILE_NAME);
	}






	if (panel) {
		delete panel;
	}

	int x;
	cin >> x;

	return 1;
}