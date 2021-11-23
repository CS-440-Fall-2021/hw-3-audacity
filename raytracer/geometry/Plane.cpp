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

Plane & Plane::operator=(const Plane &rhs)
{
    a = Point3D(rhs.a);
    n = Vector3D(rhs.n);
    material_ptr = rhs.material_ptr;

    return *this;
}


// Taken from: https://stackoverflow.com/questions/23975555/how-to-do-ray-plane-intersection

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    double denom = n * ray.d;

    if ( abs(denom) > 0.0001f )
    {
        double t_ = (a - ray.o) * n;
        t_ /= denom;

        if (t_ >= 0)
            {
                t = t_;

                s.hit = true;
                s.material_ptr = material_ptr;
                s.hit_point = ray.o + (t * ray.d);
                s.t = t;
                s.normal = Vector3D(n);

                return true;
            }
    }

    s.hit = false;
    return false;
}

BBox Plane::getBBox() const
{
    // Not sure
}