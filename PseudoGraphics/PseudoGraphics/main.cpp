#include "pg_components_factory.h"


#define DEBUG_ON		(1)

int main() {
	//create our factory:
	PgComponentsFactory& factory = PgComponentsFactory::getInstance();

	PgComposite* panel = factory.create(PANEL);
	PgComposite* label = factory.create(LABEL);
	PgComposite* button = factory.create(BUTTON);
	
	//create our main panel and bind all components to it:
	//PgPanel example:
	panel->setFrameType(DOUBLE_SOLID);
	panel->setBackground(DEF_PANEL_COLOR);
	panel->setDimensions({ 70, 80 });
	panel->setBasePosition({2, 2});

	
	//PgLabel example
	label->setFrameType(NONE);
	label->setBackground(DEF_LABEL_COLOR);
	label->setDimensions({ 30, 3 });
	label->setBasePosition({ 30, 5 });
	static_cast<PgLabel*>(label)->setContent("I'M PICKLE RIIIIIIIIICK");
	panel->add(label);
	//label->draw();

	button->setFrameType(SINGLE_SOLID);
	button->setBackground(DEF_BTN_COLOR);
	button->setDimensions({ 20, 6 });
	button->setBasePosition({10,10});
	static_cast<PgButton*>(button)->setButtonName("Click Me");
	panel->add(button);
	//button->draw();

	




	panel->draw();


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