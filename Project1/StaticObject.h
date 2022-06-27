#pragma once
#include "Objects.h"
class StaticObject :
	public Objects
{
public:
	StaticObject();
	/*virtual*/~StaticObject();
	bool virtual colide(MoveObject * o) { return true; }
};