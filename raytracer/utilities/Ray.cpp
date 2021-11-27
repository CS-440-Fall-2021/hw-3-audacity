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

    d.normalize();
    
    w = 1;
}


std::string Ray::to_string() const
{
    return "Ray: " + o.to_string() + " " + d.to_string() + "\n";
}