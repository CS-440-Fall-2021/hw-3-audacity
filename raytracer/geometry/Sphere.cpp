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

  return *this;
}

std::string Sphere::to_string() const
{
  return "Sphere: " + c.to_string() + "Radius: " + std::to_string(r) + "\n";
}

// Reference: Ray Tracing from the Ground Up - Kevin Suffern

bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
  // equation to solve for t: (d . d)t^2 + [2(o - c) . d]t + (o - c). (o - c) - r^2 = 0

  double _t;

  Vector3D temp = ray.o - c;

  double a = ray.d * ray.d;          // a of the quadratic equation
  double b = 2.0 * temp * ray.d;     // b of the quadratic equation
  double c = temp * temp - r * r;    // c of the quadratic equation

  double disc = b * b - 4.0 * a * c; // discriminant of the equation


  if (disc < 0.0) // if discriminant < 0, no hit, return false
    return (false);

  else
  {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    _t = (-b - e) / denom; // smaller root

    if (_t > kEpsilon) // if _t is not 0 or negative
    {
      // set t and sinfo as per intersection with the object
      t = _t;

      s.normal = (temp + t * ray.d) / r;
      s.normal.normalize();
      s.hit_point = ray.o + t * ray.d;
      s.hit = true;
      s.t = t;
      s.material_ptr = material_ptr;
      s.ray = ray;

      return true;
    }

    _t = (-b + e) / denom; // larger root

    if (_t > kEpsilon) // if t is not 0 or negative
    {
      // set t and sinfo as per intersection with the object
      t = _t;

      s.normal = (temp + t * ray.d) / r;
      s.normal.normalize();
      s.hit_point = ray.o + t * ray.d;
      s.hit = true;
      s.t = t;
      s.material_ptr = material_ptr;
      s.ray = ray;

      return true;
    }
  }

  s.hit = false;
  return false;
}

BBox Sphere::getBBox() const
{
  Point3D _min = Point3D(c.x - r, c.y - r, c.z - r);
  Point3D _max = Point3D(c.x + r, c.y + r, c.z + r);

  return BBox(_min, _max);
}