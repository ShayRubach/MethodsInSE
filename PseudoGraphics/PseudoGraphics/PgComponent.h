#pragma once
#ifndef PG_COMPONENT_H
#define PG_COMPONENT_H

class PgComponent
{
	//These methods will be overridden by the Composite - the one holding a list of the Baseclass types.

public:

	virtual void draw() = 0;
	virtual void add(PgComponent*) = 0;
	virtual void remove(const int pos) = 0;
	virtual PgComponent* getChild(const int pos) = 0;

};


#endif //PG_COMPONENT_H