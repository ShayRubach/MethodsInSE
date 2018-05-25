#pragma once
#ifndef IMOUSE_LISTENER_H
#define IMOUSE_LISTENER_H

//Test Push + gitignore test
class IMouseListener
{
public:
	virtual ~IMouseListener() = default;
	virtual bool onClick() = 0;
	virtual bool onHover() = 0;
};

#endif // !IMOUSE_LISTENER_H
