#include "Forward.h"
#include "../Tiles/Tile.h"

namespace jb
{

void CmdForward::execute() const 
{ 
	Position newPosition = advance(m_position, m_compass);
	if (m_grid.getTile(newPosition.getX(), newPosition.getY()).canOccupy())
	{
		std::cout << "forward" << std::endl; 
		m_position = newPosition;
	}
	else
	{
		std::cout << "blocked" << std::endl; 
	}
}

} // jb
