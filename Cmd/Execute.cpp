#include "Execute.h"
#include "../Navigation/Compass.h"
#include <iostream>

namespace jb
{

void CmdExecute::execute() const
{
	m_toExecute();
}


} // jb
