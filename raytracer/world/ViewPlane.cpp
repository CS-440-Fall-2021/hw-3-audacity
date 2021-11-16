#include "ViewPlane.hpp"

ViewPlane::ViewPlane()
{
    // Not sure
    top_left = Point3D(-320, 240, 0);
    bottom_right = Point3D(320, 240, 0);
}

int ViewPlane::get_hres() const
{
    return bottom_right.x - top_left.x;
}

void ViewPlane::set_hres(int hres)
{
    top_left.x = -hres / 2;
    bottom_right.x = hres / 2;
}

int ViewPlane::get_vres() const
{
    return top_left.y - bottom_right.y;
}

void ViewPlane::set_vres(int vres)
{
    top_left.x = vres / 2;
    bottom_right.x = -vres / 2;
}