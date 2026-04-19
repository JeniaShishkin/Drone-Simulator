#include "PointOfView.h"

namespace jb
{
void CmdPointOfView::execute() const
{
    if (!m_ctx.activeSensor)
    {
        std::cout << "No sensor selected\n";
        return;
    }
    m_ctx.activeSensor->scan(m_ctx.m_grid, m_ctx.m_position, m_ctx.m_compass);
}
}
