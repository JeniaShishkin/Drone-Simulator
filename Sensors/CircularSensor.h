#ifndef __CIRCULARSENSOR_H__
#define __CIRCULARSENSOR_H__

#include "Sensor.h"
#include "../Navigation/Compass.h"
namespace jb
{

class CircularSensor : public Sensor
{
public:
    CircularSensor() = default;
    virtual void scan(const WorldGrid& grid, const Position& pos, const Compass& compass) const override;
    ~CircularSensor() = default;
};
}

#endif
