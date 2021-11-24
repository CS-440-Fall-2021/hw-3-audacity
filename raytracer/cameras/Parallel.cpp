#include "Parallel.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

Parallel::Parallel()
{
    dir = Vector3D(0, 0, -1);
}

Parallel::Parallel(float c)
{
    dir = Vector3D(c);
    dir.normalize();
}

Parallel::Parallel(float x, float y, float z)
{
    dir = Vector3D(x, y, z);
    dir.normalize();
}

Parallel::Parallel(const Vector3D &d)
{
    dir = Vector3D(d);
    dir.normalize();
}


Parallel::Parallel(const Parallel &camera)
{
    dir = Vector3D(camera.dir);
}

Parallel &Parallel::operator=(const Parallel &other)
{
    dir = Vector3D(other.dir);

    return *this;
}


Vector3D Parallel::get_direction(const Point3D &p) const
{
    return dir;
}