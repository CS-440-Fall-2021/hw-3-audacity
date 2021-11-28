#include "Plane.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

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

Plane &Plane::operator=(const Plane &rhs)
{
    a = Point3D(rhs.a);
    n = Vector3D(rhs.n);
    material_ptr = rhs.material_ptr;

    return *this;
}

std::string Plane::to_string() const
{
    return "Plane: " + a.to_string() + n.to_string() + "\n";
}

// Reference: Ray Tracing from the Ground Up - Kevin Suffern

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    // equation for t:  t = (a - o) . n / d . n

    double denom = n * ray.d; // denominator of the equation

    if (abs(denom) > kEpsilon) // if denominator not 0 or negative
    {
        double t_ = (a - ray.o) * n; // numerator of the equation
        t_ /= denom;

        if (t_ > kEpsilon) // if t is not 0 or negative
        {
            // set t and sinfo as per intersection with the object
            t = t_;

            s.hit = true;
            s.material_ptr = material_ptr;
            s.hit_point = ray.o + (t * ray.d);
            s.t = t;
            s.normal = n;
            s.ray = ray;

            return true;
        }
    }

    s.hit = false;
    return false;
}

BBox Plane::getBBox() const
{
    
}