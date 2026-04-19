#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "../Navigation/Position.h"
#include "../Navigation/WorldGrid.h"
#include "../Navigation/Compass.h"
#include "../Sensors/Sensor.h"

namespace jb
{
struct Context
{

    explicit Context(const WorldGrid& g, const Position& p, const Compass& c) : m_grid(g), m_position(p), m_compass(c) { }
    ~Context() = default;
    
    const Sensor* activeSensor = nullptr;
    const WorldGrid& m_grid;
    const Position& m_position;
    const Compass& m_compass;

};

}


#endif