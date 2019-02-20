#include "PC.h"

PC_Entity::PC_Entity()
{
	stopped = false;
}

void PC_Entity::run()
{
	while(!stopped)
	{
		
	}
	stopped = false;
}

void PC_Entity::stop()
{
	stopped = true;
}