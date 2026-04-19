#include "TurnRight.h"
#include "../Navigation/Compass.h"
#include <iostream>

namespace jb
{

void CmdTurnRight::execute() const
{
	turnRight(&m_compass);
	std::cout << "turned right. now facing " << m_compass.getHeading() << std::endl;
}


} // jb
