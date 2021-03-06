#include "ViewPlane.hpp"

ViewPlane::ViewPlane()
{
    top_left = Point3D(-320, 240, 0);
    bottom_right = Point3D(320, 240, 0);
    
    hres = 640;
    vres = 480;
    
    normal = Vector3D(0, 0, -1);
}

int ViewPlane::get_hres() const
{
    return hres;
}

void ViewPlane::set_hres(int _hres)
{
    hres = _hres;
}

int ViewPlane::get_vres() const
{
    return vres;
}

void ViewPlane::set_vres(int _vres)
{  
    vres = _vres;
}