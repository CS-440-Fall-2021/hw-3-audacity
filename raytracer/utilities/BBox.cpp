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
    // Not sure
}

bool BBox::hit(const Ray &ray, float &t_enter, float &t_exit) const
{
    double ox = ray.o.x;
    double oy = ray.o.y;
    double oz = ray.o.z;
    double dx = ray.d.x;
    double dy = ray.d.y;
    double dz = ray.d.z;
    double x0 = pmin.x;
    double x1 = pmax.x;
    double y0 = pmin.y;
    double y1 = pmax.y;
    double z0 = pmin.z;
    double z1 = pmax.z;

    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;

    double a = 1.0 / dx;
    if (a >= 0)
    {
        tx_min = (x0 - ox) * a;
        tx_max = (x1 - ox) * a;
    }
    else
    {
        tx_min = (x1 - ox) * a;
        tx_max = (x0 - ox) * a;
    }

    double b = 1.0 / dy;
    if (b >= 0)
    {
        ty_min = (y0 - oy) * b;
        ty_max = (y1 - oy) * b;
    }
    else
    {
        ty_min = (y1 - oy) * b;
        ty_max = (y0 - oy) * b;
    }

    double c = 1.0 / dz;
    if (c >= 0)
    {
        tz_min = (z0 - oz) * c;
        tz_max = (z1 - oz) * c;
    }
    else
    {
        tz_min = (z1 - oz) * c;
        tz_max = (z0 - oz) * c;
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

// Extend this bbox, if necessary, to include g or b.
void BBox::extend(Geometry *g)
{
}

void BBox::extend(const BBox &b)
{
}

// Does this BBox contain p? True even when p lies on a boundary.
bool BBox::contains(const Point3D &p)
{
}

// Does this BBox overlap with g or b?
bool BBox::overlaps(Geometry *g)
{
}

bool BBox::overlaps(const BBox &b)
{
}