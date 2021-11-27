#include "Cosine.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include <iostream>

Cosine::Cosine()
{
    color = RGBColor();
}

Cosine::Cosine(float c)
{
    color = RGBColor(c);
}

Cosine::Cosine(float r, float g, float b)
{
    color = RGBColor(r, g, b);
}

Cosine::Cosine(const RGBColor &c)
{
    color = RGBColor(c);
}


Cosine::Cosine(const Cosine &other)
{
    color = RGBColor(other.color);
}

Cosine & Cosine::operator=(const Cosine &other)
{
    color = RGBColor(other.color);
    
    return *this;
}


/* Returned shade is: color * cos \theta.
    \theta is the angle between the normal at the hit pont and the ray.
    Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
*/
RGBColor Cosine::shade(const ShadeInfo &sinfo) const
{
    return color * ( sinfo.normal * ( -1 * sinfo.ray.d ) );
}
