#include "Ray.hpp"

Ray::Ray()
{
    o = Point3D();
    d = Vector3D();
    w = 1;
}

Ray::Ray(const Point3D &origin, const Vector3D &dir)
{
    o = Point3D(origin);
    d = Vector3D(dir);
    w = 1;
}


std::string Ray::to_string() const
{
    // Not sure how to represent as a string
}