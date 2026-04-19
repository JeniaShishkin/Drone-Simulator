#include "DistanceSensor.h"
#include "../Navigation/WorldGrid.h"
#include "../Navigation/Position.h"
#include "../Tiles/TIle.h"

namespace jb
{
void DistanceSensor::scan(const WorldGrid& grid, const Position& pos, const Compass& compass) const 
{ 
    int x = pos.getX();
    int y = pos.getY();

    Position start{x - 3, y - 2};
    Position end  {x - 1, y + 2}; 

    int baseX = start.getX();
    int centerY = y;

    for (auto it = grid.begin(start, end); it != grid.end(start, end); ++it)
    {
        int ix = it.getCurrentX();
        int iy = it.getCurrentY();

        int dx = (start.getX() + 2) - ix; // row index: 0,1,2
        int allowedWidth = dx * 2 + 1;    // 1,3,5

        int leftBound = centerY - dx;
        int rightBound = centerY + dx;

        // Filter logic
        if (iy < leftBound || iy > rightBound)
            continue;

        // optional row separation
        if (iy == leftBound)
            std::cout << '\n';

        std::cout << (*it)->symbol();
    }

    std::cout << '\n';
}
}