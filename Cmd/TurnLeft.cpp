#include "TurnLeft.h"
#include "../Navigation/Compass.h"
#include <iostream>

namespace jb
{

void CmdTurnLeft::execute() const
{
	turnLeft(&m_compass);
	std::cout << "turned left. now facing " << m_compass.getHeading() << std::endl;
}


} // jb
