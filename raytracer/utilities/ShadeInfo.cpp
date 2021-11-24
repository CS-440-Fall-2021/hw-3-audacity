#include "ShadeInfo.hpp"
#include "../materials/Material.hpp"
#include "../world/World.hpp"

ShadeInfo::ShadeInfo(const World &wr)
{
    w = &wr;
}