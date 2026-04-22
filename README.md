# Drone Simulator

This project is a drone simulation application built with a strong focus on maintainable architecture and iterative development.

## Key Principles

- **SOLID design** drives the code structure:
  - Single Responsibility: each class and module has a clear, focused purpose.
  - Open/Closed: components are designed for extension without modification.
  - Liskov Substitution: abstractions are used so implementations can be swapped safely.
  - Interface Segregation: interfaces are kept minimal and specific.
  - Dependency Inversion: high-level components depend on abstractions, not concrete classes.

- **Agile methodology** guides development:
  - Incremental improvements and frequent refactoring.
  - Responsive adaptation to requirements.
  - Emphasis on working code and continuous enhancement.

## Project Structure

The project is organized into the following folders and files:

### Root Files
- `BaseEssentials.h` — Base utilities and essentials
- `Drone.cpp` — Drone class implementation
- `Drone.h` — Drone class header
- `main.cpp` — Simulation entry point
- `README.md` — This file

### Cmd/ Folder
Contains command classes for controlling the drone:
- `Command.h` — Abstract base class for commands
- `Context.h` — Context for command execution
- `Execute.cpp`, `Execute.h` — Execute command (runs a function)
- `Forward.cpp`, `Forward.h` — Forward command (moves drone forward)
- `Map.cpp`, `Map.h` — Map command (displays the world grid)
- `PointOfView.cpp`, `PointOfView.h` — PointOfView command (shows drone's view)
- `SetSensor.h` — SetSensor command (sets active sensor)
- `TurnLeft.cpp`, `TurnLeft.h` — TurnLeft command (turns drone left)
- `TurnRight.cpp`, `TurnRight.h` — TurnRight command (turns drone right)

### Navigation/ Folder
Handles navigation and positioning:
- `Compass.cpp`, `Compass.h` — Compass class for direction
- `Position.cpp`, `Position.h` — Position class for coordinates
- `WorldGrid.cpp`, `WorldGrid.h` — WorldGrid class for the simulation environment

### Sensors/ Folder
Sensor implementations for obstacle detection:
- `CircularSensor.cpp`, `CircularSensor.h` — Circular sensor
- `DistanceSensor.cpp`, `DistanceSensor.h` — Distance sensor
- `Sensor.h` — Abstract base sensor class
- `WideSensor.cpp`, `WideSensor.h` — Wide sensor

### Tiles/ Folder
Tile types for the world grid:
- `EmptyTile.cpp`, `EmptyTile.h` — Empty tile
- `ExitTile.h` — Exit tile
- `Tile.cpp`, `Tile.h` — Abstract base tile class
- `WallTile.h` — Wall tile

### Networking/ Folder
Handles port-based network communication for the simulator:
- `NetworkHandler.cpp`, `NetworkHandler.h` — Core network manager using TCP sockets and Winsock.
  - Binds to a configured port and listens for incoming client connections.
  - Uses non-blocking sockets plus `select()` to manage multiple active connections.
  - Reads newline-terminated input from connected clients and sends responses back over the same socket.
- `NaiveNetworkHandler.cpp`, `NaiveNetworkHandler.h` — Simple concrete implementation of `NetworkHandler`.

The networking layer enables remote control and telemetry by accepting commands over a network port. Incoming client connections are managed through a socket listener, and communication is exchange-driven using port-based TCP streams.

## Implemented Commands

The simulation supports the following commands for controlling the drone. All commands (except "exit") consume energy based on a fixed consumption model, which can be configured before compilation.

## Sensor Types and Viewing Bounds

The drone can be equipped with different sensors, each with unique viewing ranges:

- **Circular Sensor** (`s_a`): Provides a narrow circular field of view around the drone with configurable bounds per heading.
  - NORTH: `{ {-2, -1}, { 1, 1} }`
  - EAST: `{ {-1, -1}, { 1, 2} }`
  - SOUTH: `{ {-1, -1}, { 2, 1} }`
  - WEST: `{ {-1, -2}, { 1, 1} }`

- **Wide Sensor** (`s_b`): Provides an extended field of view with wider coverage.
  - NORTH: `{ {-1, -1}, {-1, 2} }`
  - EAST: `{ {-2, 1}, { 2, 1} }`
  - SOUTH: `{ {1, -2}, { 1, 2} }`
  - WEST: `{ {-2, -1}, { 2, -1} }`

- **Distance Sensor** (`s_c`): Specialized for detecting objects at greater distances.
  - NORTH: `{ {-3, -2}, {-1, 2} }`
  - EAST: `{ {-2, 1}, { 2, 3} }`
  - SOUTH: `{ {1, -2}, { 3, 2} }`
  - WEST: `{ {-2, -3}, {-2, -1} }`

## Energy System

The drone operates with a finite energy budget. Each command consumes a fixed amount of energy through the `FixedConsumption` template class. Commands cannot execute if insufficient energy is available. The exit command has no energy cost and allows the drone to terminate the simulation at any time.

## Tile System

The world grid is composed of different tile types:

- **Empty Tile** (` `): Passable, allows drone to occupy.
- **Wall Tile** (`#`): Impassable, blocks drone movement.
- **Exit Tile** (`E`): Passable goal tile that triggers exit condition when reached.

## Goal

This repository is intended as an example of building a small system with clean, extensible design while following agile development practices and SOLID principles.

