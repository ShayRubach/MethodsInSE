#pragma once
#ifndef PG_COMPONENTS_FACTORY_H
#define PG_COMPONENTS_FACTORY_H

//todo: remove these includes and uses. include all classes so we can write the create() method
#include <iostream>
using std::string;

class PgComponentsFactory
{
private:
	PgComponentsFactory();
	static PgComponentsFactory* instance;
public:
	PgComponentsFactory* getInstance();
	//PgComponent* create(string product_name);

	~PgComponentsFactory();
};

#endif // !PG_COMPONENTS_FACTORY_H
