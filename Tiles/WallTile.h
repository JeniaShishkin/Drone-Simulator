#ifndef __WallTile_h__
#define __WallTile_h__

#include "Tile.h"

namespace jb
{

class WallTile : public Tile 
{
	virtual bool canOccupy() const { return false; }
	virtual char symbol() const override { return '#'; } 
};

} // jb

#endif
