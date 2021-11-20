#include "BBox.hpp"
#include "../geometry/Geometry.hpp"
#include "Ray.hpp"

BBox::BBox(const Point3D& min, const Point3D& max)
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
    
}

// Extend this bbox, if necessary, to include g or b.
void BBox::extend(Geometry* g);
void BBox::extend(const BBox& b);

// Does this BBox contain p? True even when p lies on a boundary.
bool BBox::contains(const Point3D& p);

// Does this BBox overlap with g or b?
bool BBox::overlaps(Geometry* g);
bool BBox::overlaps(const BBox& b);