#ifndef __TILE_H__
#define __TILE_H__

#include "../BaseEssentials.h"

namespace jb
{

class Tile : private BaseEssentials 
{
public:
	enum ExitBehavior { KEEP_GOING, EXIT };
	Tile(ExitBehavior exitBehavior = KEEP_GOING) : m_exitBehavior(exitBehavior) { }

	bool shouldExit() const { return m_exitBehavior == EXIT; }
	virtual char symbol() const = 0;
	virtual bool canOccupy() const = 0;

private:
	const ExitBehavior m_exitBehavior;
};

} // jb

#endif
