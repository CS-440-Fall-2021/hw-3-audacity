#include "ViewPlane.hpp"

ViewPlane::ViewPlane()
{
    top_left = Point3D(-320, 240, 0);
    bottom_right = Point3D(320, 240, 0);
    
    hres = 640;
    vres = 480;
}

int ViewPlane::get_hres() const
{
    // return bottom_right.x - top_left.x;
    
    return hres;
}

void ViewPlane::set_hres(int _hres)
{
    // top_left.x = -hres / 2;
    // bottom_right.x = hres / 2;

    hres = _hres;
}

int ViewPlane::get_vres() const
{
    // return top_left.y - bottom_right.y;

    return vres;
}

void ViewPlane::set_vres(int _vres)
{
    // top_left.x = vres / 2;
    // bottom_right.x = -vres / 2;
    
    vres = _vres;
}