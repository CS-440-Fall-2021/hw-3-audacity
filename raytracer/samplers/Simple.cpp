#include "Simple.hpp"
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

Simple::Simple(Camera *c_ptr, ViewPlane *v_ptr)
    : Sampler(c_ptr, v_ptr) {};

Simple::Simple(const Simple &camera)
    : Sampler(camera.camera_ptr, camera.viewplane_ptr) {};

Simple & Simple::operator=(const Simple &other)
{
    camera_ptr = other.camera_ptr;
    viewplane_ptr == other.viewplane_ptr;

    return *this;
}

std::vector<Ray> Simple::get_rays(int px, int py) const
{
    std::vector<Ray> rays;

    double scaled_px, scaled_py;

    scaled_px = ( (double)px / (double)viewplane_ptr->get_hres() ) * (viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x);

    scaled_py = ( (double)py / (double)viewplane_ptr->get_vres() ) * (viewplane_ptr->top_left.y - viewplane_ptr->bottom_right.y);

    Point3D pixel = viewplane_ptr->top_left + Vector3D(scaled_px, scaled_py, 0);

    rays.push_back( Ray(pixel, camera_ptr->get_direction(pixel)) );

    return rays;
}