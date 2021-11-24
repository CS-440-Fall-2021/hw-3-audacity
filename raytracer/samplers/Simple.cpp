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

    Point3D pixel = viewplane_ptr->top_left + Vector3D(px, py, 0);

    rays.push_back( Ray(pixel, camera_ptr->get_direction(pixel)) );

    return rays;
}