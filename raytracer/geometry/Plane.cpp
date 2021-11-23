#include "Plane.hpp"

Plane::Plane() : Geometry()
{
    n = Vector3D(0, 1, 0);
    a = Point3D();
}

Plane::Plane(const Point3D &pt, const Vector3D &_n) : Geometry()
{
    a = Point3D(pt);
    n = Vector3D(_n);

    n.normalize();
}


Plane::Plane(const Plane &object)
{
    a = Point3D(object.a);
    n = Vector3D(object.n);
    material_ptr = object.material_ptr;
}

Plane & Plane::operator=(const Plane &rhs)
{
    a = Point3D(rhs.a);
    n = Vector3D(rhs.n);
    material_ptr = rhs.material_ptr;

    return *this;
}