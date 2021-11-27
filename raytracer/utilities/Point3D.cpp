#include "Point3D.hpp"
#include "Vector3D.hpp"

Point3D::Point3D()
{
    x = y = z = 0;
}

Point3D::Point3D(float c)
{
    x = y = z = c;
}

Point3D::Point3D(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

std::string Point3D::to_string() const
{
    std::string x_s = std::to_string(x);
    std::string y_s = std::to_string(y);
    std::string z_s = std::to_string(z);

    return x_s + " " + y_s + " " + z_s;
}
  
Point3D Point3D::operator-() const
{
    return Point3D(-x, -y, -z);
}

Vector3D Point3D::operator-(const Point3D &p) const
{
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D Point3D::operator+(const Vector3D &v) const
{
    return Point3D(x + v.x, y + v.y, z + v.z);
}

Point3D Point3D::operator-(const Vector3D &v) const
{
    return Point3D(x - v.x, y - v.y, z - v.z);
}

Point3D Point3D::operator*(const float s) const
{
    return Point3D(x * s, y * s, z * s);
}


float Point3D::d_squared(const Point3D &p) const
{
    return pow(p.x - x, 2) + pow(p.y - y, 2) + pow(p.z - z, 2); 
}

float Point3D::distance(const Point3D &p) const
{
    return sqrt(d_squared(p));
}


Point3D operator*(const float a, const Point3D &pt)
{
    return Point3D(pt.x * a, pt.y * a, pt.z * a);
}


Point3D min(const Point3D& a, const Point3D& b)
{

}

Point3D max(const Point3D& a, const Point3D& b)
{
    
}