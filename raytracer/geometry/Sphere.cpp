#include "Sphere.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

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

bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
  double _t;
  Vector3D temp = ray.o - c;
  double a = ray.d * ray.d;
  double b = 2.0 * temp * ray.d;
  double c = temp * temp - r * r;
  double disc = b * b - 4.0 * a * c;

  if (disc < 0.0)
    return (false);
  else
  {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    _t = (-b - e) / denom; // smaller root

    if (_t > kEpsilon)
    {
      t = _t;
      s.normal = (temp + t * ray.d) / r;
      s.hit_point = ray.o + t * ray.d;
      s.hit = true;
      s.t = t;
      s.material_ptr = material_ptr;
      return true;
    }

    _t = (-b + e) / denom; // larger root

    if (_t > kEpsilon)
    {
      t = _t;
      s.normal = (temp + t * ray.d) / r;
      s.hit_point = ray.o + t * ray.d;
      s.hit = true;
      s.t = t;
      s.material_ptr = material_ptr;
      return true;
    }
  }

  s.hit = false;
  return false;
}