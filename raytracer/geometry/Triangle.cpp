#include "Triangle.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

Triangle::Triangle() : Geometry()
{
  v0 = Point3D();
  v1 = Point3D();
  v2 = Point3D();
}

Triangle::Triangle(const Point3D &_v0, const Point3D &_v1, const Point3D &_v2) : Geometry()
{
  v0 = Point3D(_v0);
  v1 = Point3D(_v1);
  v2 = Point3D(_v2);
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

  return *this;
}

std::string Triangle::to_string() const
{
  return "Triangle: " + v0.to_string() + v1.to_string() + v2.to_string() + "\n";
}

// Reference: Ray Tracing from the Ground Up - Kevin Suffern

bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
  double a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
  double e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
  double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.z - ray.o.z;

  double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
  double q = g * i - e * k, _s = e * j - f * i;

  double inv_denom = 1.0 / (a * m + b * q + c * _s);

  double e1 = d * m - b * n - c * p;
  double beta = e1 * inv_denom;

  if (beta < 0.0)
  {
    s.hit = false;
    return false;
  }

  double r = e * l - h * i;
  double e2 = a * n + d * q + c * r;
  double gamma = e2 * inv_denom;

  if (gamma < 0.0)
  {
    s.hit = false;
    return false;
  }

  if (beta + gamma > 1.0)
  {
    s.hit = false;
    return false;
  }

  double e3 = a * p - b * r + d * _s;
  double _t = e3 * inv_denom;

  if (_t < kEpsilon)
  {
    s.hit = false;
    return false;
  }

  // set t and sinfo as per intersection with the object
  t = _t;

  s.normal = (v1 - v0) ^ (v2 - v0);
  s.normal.normalize();
  s.hit_point = ray.o + t * ray.d;
  s.hit = true;
  s.material_ptr = material_ptr;
  s.t = t;
  s.ray = ray;

  return true;
}

BBox Triangle::getBBox() const
{
  Point3D _max = max(v0, v1);
  _max = max(_max, v2);
  
  Point3D _min = min(v0, v1);
  _min = min(_min, v2);

  return BBox(_min, _max);
}