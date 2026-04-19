#ifndef __Command_h__
#define __Command_h__

#include "../BaseEssentials.h"

namespace jb
{

struct Command : private BaseEssentials
{
	virtual void execute() const = 0;
};

} // jb

#endif
