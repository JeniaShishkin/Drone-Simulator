#include "Position.h"
#include <map>
#include <stdexcept>

namespace jb
{

struct PositionDelta
{
	int deltaX;
	int deltaY;
};

using DeltasMap = std::map<Compass, const PositionDelta>;
static const DeltasMap DELTAS { 
	{ NORTH, { -1, 0 } }, 
	{ EAST, { 0 , 1 } }, 
	{ SOUTH, { 1 , 0 } }, 
	{ WEST, { 0 , -1 } }
};


Position advance(const Position &cur, const Compass &heading)
{
	DeltasMap::const_iterator deltaItr = DELTAS.find(heading);
	if (deltaItr == DELTAS.end())
	{
		throw std::runtime_error{"Unprocessable compass heading"};
	}
	return Position(cur.getX() + deltaItr->second.deltaX, cur.getY() + deltaItr->second.deltaY);
}

} // jb
