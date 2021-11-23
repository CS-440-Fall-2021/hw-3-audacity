#include "Sphere.hpp"

Sphere::Sphere() : Geometry()
{
  c = Point3D();
  r = 0;
}

Sphere::Sphere(const Point3D &center, float radius) : Geometry()
{
  c = Point3D(center);
  r = radius;
}

Sphere::Sphere(const Sphere &object)
{
  c = Point3D(object.c);
  r = object.r;
}

Sphere &Sphere::operator=(const Sphere &rhs)
{
  c = Point3D(rhs.c);
  r = rhs.r;
}