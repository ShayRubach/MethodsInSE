#include "pg_components_factory.h"

//this works due to c++11 local statics approach:
PgComponentsFactory&
PgComponentsFactory::getInstance() {
	static PgComponentsFactory instance;
	return instance;
}

PgComponent* 
PgComponentsFactory::create(const enum PgProduct& product) {
	switch (product)
	{
	case LABEL:
		return new PgLabel(); 
		break;
	case BUTTON:
		return new PgButton();
		break;
	case PANEL:
		return new PgPanel();
		break;
	case CHECK_LIST:
		return new PgCheckList();
		break;
	case COMBO_BOX:
		return new PgComboBox();
		break;
	case MESSAGE_BOX:
		return new PgMessageBox();
		break;
	case RADIO_BOX:
		return new PgRadioBox();
		break;
	case NUMERIC_BOX:
		return new PgNumericBox();
	case TEXT_BOX:
		return new PgTextBox();
		break;
	default:
		break;
	}
	return NULL;
}
