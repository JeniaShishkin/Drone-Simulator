#include "WideSensor.h"
#include "../Navigation/WorldGrid.h"
#include "../Navigation/Position.h"
#include "../Tiles/Tile.h"

namespace jb
{
void WideSensor::scan(const WorldGrid& grid, const Position& pos, const Compass& compass) const 
{ 
    Position start{pos.getX() - 1,pos.getY() - 2};
    
    Position end{pos.getX() - 1,pos.getY() + 3};
    int prevX = start.getX();
    for (auto it = grid.begin(start, end); it != grid.end(start, end); ++it)
    {
        if (it.getCurrentX() != prevX)
        {
            std::cout << '\n';
            prevX = it.getCurrentX();
        }
        std::cout << "I enter here" << std::endl;
        std::cout << (*it)->symbol(); // or however you print
    }
    std::cout << std::endl;
}
}