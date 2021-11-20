#include "Perspective.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

Perspective::Perspective()
{
    pos = Point3D();
}

Perspective::Perspective(float c)
{
    pos = Point3D(c);
}

Perspective::Perspective(float x, float y, float z)
{
    pos = Point3D(x, y, z);
}

Perspective::Perspective(const Point3D &pt)
{
    pos = Point3D(pt);
}


Perspective::Perspective(const Perspective &camera)
{
    pos = Point3D(camera.pos);
}

Perspective &Perspective::operator=(const Perspective &other)
{
    pos = Point3D(other.pos);

    return *this;
}


Vector3D Perspective::get_direction(const Point3D &p) const
{
    // Not sure
}