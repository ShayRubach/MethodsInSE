//This header file is used to hold every shared constants between the project components
#pragma once
#ifndef PG_CONSTANTS_H
#define PG_CONSTANTS_H

//special char set:
//single line
#define BORDER_OFFSET (1)
#define SINGLE_TOP_LEFT_CORNER '\xDA'
#define SINGLE_TOP_RIGHT_CORNER '\xBF'
#define SINGLE_BTM_LEFT_CORNER '\xC0'
#define SINGLE_BTM_RIGHT_CORNER '\xD9'
#define SINGLE_LINE_VERTICAL '\xB3'
#define SINGLE_LINE_HORIZONTAL '\xC4'
//double line
#define DASHED_TOP_LEFT_CORNER '\xC9'
#define DASHED_TOP_RIGHT_CORNER '\xBB'
#define DASHED_BTM_LEFT_CORNER '\xC8'
#define DASHED_BTM_RIGHT_CORNER '\xBC'
#define DASHED_LINE_VERTICAL '\xBA'
#define DASHED_LINE_HORIZONTAL '\xCD'

#define BACKSPACE '\x08'
#define SPACE '\x20'
#define CHAR_RESET '\x0'

//list symbols:
#define SYM_BULLET "( )"
#define SYM_MARKER "<---"
#define SYM_SPACE ' '
#define SYM_CLEAR  "    "
#define SYM_CHOICE '*'
#define SYM_CHOICE_OFFSET (3)
#define PROMPT_OFFSET (36)




#endif // !PG_CONSTANTS_H


