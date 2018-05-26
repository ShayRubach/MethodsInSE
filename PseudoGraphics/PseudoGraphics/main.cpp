#include "pg_components_factory.h"

#define APP_RGB (90|10|30)
#define DEBUG_ON		(1)

int main() {
	//create our factory:
	PgComponentsFactory& factory = PgComponentsFactory::getInstance();

	PgComposite* panel = factory.create(PANEL);
	PgComposite* label1 = factory.create(LABEL);
	PgComposite* label2 = factory.create(LABEL);
	PgComposite* button = factory.create(BUTTON);

	panel->setFrameType(DOUBLE_SOLID);
	panel->setBackground(50|50|50);
	panel->setDimensions({ 30, 30 });
	panel->setBasePosition({ 1, 1 });
	panel->draw();
	


	//PgLabel example
	label1->setFrameType(DOUBLE_SOLID);
	label1->setBackground(APP_RGB);
	label1->setDimensions({ 10, 10 });
	label1->setBasePosition({ 10, 10 });
	static_cast<PgLabel*>(label1)->setContent("I'M PICKLE RIIIIIIIIIIIIIIIIIIIIIIIIIIIICK");

	
	//PgLabel example
	label2->setFrameType(NONE);
	label2->setBackground(APP_RGB);
	label2->setDimensions({ 10, 10 });
	label2->setBasePosition({ 10, 10 });
	static_cast<PgLabel*>(label2)->setContent("PRESS ME");

	button->setFrameType(SINGLE_SOLID);
	button->setBackground(10|20|30);
	button->setBasePosition({10,10});
	button->setDimensions({ 20, 20 });
	button->add(label2);
	button->draw();

	
	if (!DEBUG_ON) {
		remove(DBG_FILE_NAME);
	}

	int x;
	cin >> x;

	if (panel) {
		delete panel;
	}
	


	return 1;
}