#include "BBox.hpp"
#include "../geometry/Geometry.hpp"
#include "Constants.hpp"
#include "Ray.hpp"

BBox::BBox(const Point3D &min, const Point3D &max)
{
    pmin = Point3D(min);
    pmax = Point3D(max);
}

std::string BBox::to_string() const
{
    return "BBox: " + pmin.to_string() + pmax.to_string() + "\n";
}

bool BBox::hit(const Ray &ray, float &t_enter, float &t_exit) const
{
    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;

    double a = 1.0 / ray.d.x;
    if (a >= 0)
    {
        tx_min = (pmin.x - ray.o.x) * a;
        tx_max = (pmax.x - ray.o.x) * a;
    }
    else
    {
        tx_min = (pmax.x - ray.o.x) * a;
        tx_max = (pmin.x - ray.o.x) * a;
    }

    double b = 1.0 / ray.d.y;
    if (b >= 0)
    {
        ty_min = (pmin.y - ray.o.y) * b;
        ty_max = (pmax.y - ray.o.y) * b;
    }
    else
    {
        ty_min = (pmax.y - ray.o.y) * b;
        ty_max = (pmin.y - ray.o.y) * b;
    }

    double c = 1.0 / ray.d.z;
    if (c >= 0)
    {
        tz_min = (pmin.z - ray.o.z) * c;
        tz_max = (pmax.z - ray.o.z) * c;
    }
    else
    {
        tz_min = (pmax.z - ray.o.z) * c;
        tz_max = (pmin.z - ray.o.z) * c;
    }

    double t0, t1;

    // find largest entering t value

    if (tx_min > ty_min)
        t0 = tx_min;
    else
        t0 = ty_min;

    if (tz_min > t0)
        t0 = tz_min;

    // find smallest exiting t value

    if (tx_max < ty_max)
        t1 = tx_max;
    else
        t1 = ty_max;

    if (tz_max < t1)
        t1 = tz_max;

    if (t0 < t1 && t1 > kEpsilon)
    {
        t_enter = t0;
        t_exit = t1;
        return true;
    }

    return false;
}

void BBox::extend(Geometry* g)
{
    this->extend(g->getBBox());
}

void BBox::extend(const BBox& b)
{
    pmin = min(pmin, b.pmin);
    pmax = max(pmax, b.pmax);
}


bool BBox::contains(const Point3D& p)
{
    if  ( (pmin.x <= p.x && pmax.x >= p.x) &&
          (pmin.y <= p.y && pmax.y >= p.y) &&
          (pmin.z <= p.z && pmax.z >= p.z)
        )
        return true;
    
    return false;
}


bool BBox::overlaps(Geometry* g)
{
    return this->overlaps(g->getBBox());
}

bool BBox::overlaps(const BBox& b)
{
    if  ( (pmin.x <= b.pmax.x && pmax.x >= b.pmin.x) &&
          (pmin.y <= b.pmax.y && pmax.y >= b.pmin.y) &&
          (pmin.z <= b.pmax.z && pmax.z >= b.pmin.z)
        )
        return true;
    
    return false;
}