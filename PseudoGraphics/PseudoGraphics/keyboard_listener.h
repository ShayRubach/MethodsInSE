#pragma once
#ifndef IKEYBOARD_LISTENER_H
#define IKEYBOARD_LISTENER_H

class IKeyboardListener
{
public:
	virtual ~IKeyboardListener() = default;
	virtual bool onKeyPressed() = 0;
};

#endif // IKEYBOARD_LISTENER_H