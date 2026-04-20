#ifndef __Drone_h__
#define __Drone_h__

#include <memory>
#include <vector>
#include <unordered_map>

#include "Cmd/Context.h"
#include "Navigation/Compass.h"
#include "Navigation/Position.h"
#include "Navigation/WorldGrid.h"
#include "Sensors/WideSensor.h"
#include "Sensors/DistanceSensor.h"
#include "Sensors/CircularSensor.h"
namespace jb
{

using TypeId = char;
class Drone 
{
public:
	using Sensors = std::vector<std::unique_ptr<Sensor>>;
	Drone(WorldGrid grid, Compass compass, Position position, unsigned int energy, Sensors sensors) : 
		m_grid(grid), m_compass(compass), m_position(position), m_sensors(sensors) { }

	~Drone() = default;
private:
	WorldGrid m_grid;
	Compass m_compass;
	Position m_position;

	unsigned int m_energy;
	std::vector<std::unique_ptr<Sensor>> m_sensors;
};
//	WorldGrid theWorld;
//	//Drone d;
//	Position p{0,1};
//	Compass c{NORTH};
//    Context ctx{theWorld, p, c};

using DroneConfigByType = std::unordered_map<TypeId, Drone>;
static const DroneConfigByType DRONE_CONFIGS = {
	{'A', Drone{WorldGrid{}, Compass{NORTH}, Position{0,1}, 300, {std::make_unique<WideSensor>()}}},
	{'B', Drone{WorldGrid{}, Compass{NORTH}, Position{0,1}, 500, {std::make_unique<WideSensor>(), std::make_unique<CircularSensor>()}}},
	{'C', Drone{WorldGrid{}, Compass{NORTH}, Position{0,1}, 400, {std::make_unique<WideSensor>()}}},


}; 


} // jb


#endif
