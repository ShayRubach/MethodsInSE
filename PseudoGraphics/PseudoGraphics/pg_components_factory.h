#pragma once
#ifndef PG_COMPONENTS_FACTORY_H
#define PG_COMPONENTS_FACTORY_H

//todo: remove these includes and uses. include all classes so we can write the create() method
#include <iostream>
#include "pg_numericbox.h"
#include "pg_textbox.h"
#include "pg_panel.h"
#include "pg_messagebox.h"
#include "pg_check_list.h"
#include "pg_radiobox.h"
#include "pg_combobox.h"

typedef enum {
	LABEL,
	BUTTON,
	CHECK_LIST,
	MESSAGE_BOX,
	COMBO_BOX,
	RADIO_BOX,
	TEXT_BOX,
	NUMERIC_BOX,
	PANEL
} PgProduct;

class PgComponentsFactory final
{
private:
	//prohibiting copying and instanciating with c++11 delete modifier :)
	PgComponentsFactory() {}
	PgComponentsFactory(const PgComponentsFactory&) = delete;
	PgComponentsFactory& operator=(const PgComponentsFactory&) = delete;

public:
	static PgComponentsFactory& getInstance();
	PgComposite* create(PgProduct product);

};

#endif // !PG_COMPONENTS_FACTORY_H
