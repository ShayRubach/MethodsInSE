#pragma once
#ifndef PG_UTILS_H
#define PG_UTILS_H

#include "PgComposite.h"


const char* dbgToString(PgDebugLevel lvl);
void debug(PgDebugLevel lvl, const char *format, ...);








#endif // !PG_UTILS_H


