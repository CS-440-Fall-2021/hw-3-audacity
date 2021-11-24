#include "Triangle.hpp"

Triangle::Triangle() : Geometry()
{
  v0 = Point3D();
  v1 = Point3D();
  v2 = Point3D();
}

Triangle::Triangle(const Point3D &_v0, const Point3D &_v1, const Point3D &_v2) : Geometry()
{
  // check if points are not collinear
  if (((v1.y - v0.y) * (v2.z - v0.z)) - ((v2.y - v0.y) * (v1.z - v0.z)) != 0)
    if (((v2.x - v0.x) * (v1.z - v0.z)) - ((v1.x - v0.x) * (v2.z - v0.z)) != 0)
      if (((v1.x - v0.x) * (v2.y - v0.y)) - ((v2.x - v0.x) * (v1.y - v0.y)) != 0)
      {
        v0 = Point3D(_v0);
        v1 = Point3D(_v1);
        v2 = Point3D(_v2);
      }
}

Triangle::Triangle(const Triangle &object)
{
  v0 = Point3D(object.v0);
  v1 = Point3D(object.v1);
  v2 = Point3D(object.v2);
}

Triangle &Triangle::operator=(const Triangle &rhs)
{
  v0 = Point3D(rhs.v0);
  v1 = Point3D(rhs.v1);
  v2 = Point3D(rhs.v2);
}