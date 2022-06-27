#include "Controller.h"
#include "Screen.h"
int main()
{
	Screen screenShow;
	if (screenShow.isNoClose())
	{
		Controller c;
		c.runGame();
	}
	return 0;
}