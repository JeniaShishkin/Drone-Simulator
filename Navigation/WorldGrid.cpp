#include "WorldGrid.h"
#include "../Tiles/EmptyTile.h"
#include "../Tiles/WallTile.h"
#include "../Tiles/ExitTile.h"
#include "Position.h"
namespace jb
{
static constexpr int ASCII_RANGE = 127;
static Tile* SYMBOL_TABLE[ASCII_RANGE + 1] = { nullptr };
static EmptyTile EMPTY{};
static WallTile WALL{};
static ExitTile EXIT{};


WorldGrid::WorldGrid()
{
    m_grid.resize(NUM_ROWS, std::vector<Tile*>(NUM_COLS, &EMPTY));

    m_grid[0][0] = &WALL;
    m_grid[1][1] = &WALL;
    m_grid[2][2] = &WALL;
    m_grid[3][3] = &WALL;
    m_grid[4][0] = &WALL;
    m_grid[4][3] = &WALL;
    m_grid[5][1] = &WALL;
    m_grid[5][4] = &EXIT;
}
/* WorldGrid::WorldGrid() 
	: m_grid{} 
{ 
	                                               //========== 
	m_grid[0][0] = &WALL;                          // #            
	m_grid[1][1] = &WALL;                          //   #       
	m_grid[2][2] = &WALL;                          //     #       |
	m_grid[3][3] = &WALL;                          //       #     |
	m_grid[4][0] = &WALL; m_grid[4][3] = &WALL;    // #     #    \|/
	m_grid[5][1] = &WALL; m_grid[5][4] = &EXIT;    //   #     E	  N
	                                               // =========    
	                                            

} */

Tile &WorldGrid::getTile(int x, int y) const
{
	if (x < 0 || y < 0)
	{
		return WALL;
	}
	if (x >= NUM_ROWS || y >= NUM_COLS)
	{
		return WALL;
	}

	Tile *tile = m_grid[x][y];
	return tile ? *tile : EMPTY;
}

void WorldGrid::loadFromFile(std::ifstream& file)
{
    std::string line;
    int x = 0;
    while (std::getline(file, line) && x < NUM_ROWS)
    {
        int y = 0;
        for (char c : line)
        {
            if (y >= NUM_COLS) break;
			m_grid[x][y] = SYMBOL_TABLE[c];
            ++y;
        }
        ++x;
    };
}



WorldGrid::const_iterator::const_iterator(const WorldGrid* world, const Position start, const Position end)
    : m_world(world), m_current(start), m_start(start), m_end(end) { }

const WorldGrid::const_iterator& WorldGrid::const_iterator::operator++()
{ 	
    int curX = getCurrentX();
    int curY = getCurrentY();
    if (curX == m_end.getX() && curY == m_end.getY()) { return *this; }

    if (getCurrentY() + 1 < m_end.getY()) { m_current = Position{curX, curY + 1}; }
	
    else { m_current = Position{curX + 1, m_start.getY()}; }

    return *this;
}

bool WorldGrid::const_iterator::operator!=(const const_iterator& other) const
{
    return getCurrentX() != other.getCurrentX() || getCurrentY() != other.getCurrentY();
}

const WorldGrid::const_iterator WorldGrid::begin(const Position& start, const Position& end) const
{
    return const_iterator(this, start, end);
}

const WorldGrid::const_iterator WorldGrid::end(const Position& start, const Position& end) const
{
    return const_iterator(this, start, end);
}

void initAsciiTable()
{
    SYMBOL_TABLE['#'] = &WALL;
    SYMBOL_TABLE[' '] = &EMPTY;
    SYMBOL_TABLE['E'] = &EXIT;
}
} // jb
