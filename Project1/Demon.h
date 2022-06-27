#pragma once
#include "MoveObject.h"
class Packman;
class Board;
class Demon :
	public MoveObject
{
public:
	Demon();
	virtual ~Demon();
	void virtual move(Board &b, Packman &p) = 0;
	 bool virtual colide(MoveObject * o)=0;
};