#include "World.hpp"
#include "../cameras/Camera.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/Ray.hpp"
#include "../samplers/Sampler.hpp"
#include "../utilities/ShadeInfo.hpp"
#include <iostream>

World::World() {};

World::~World() {};

void World::add_geometry(Geometry *geom_ptr)
{
    geometry.push_back(geom_ptr);
}

void World::set_camera(Camera *c_ptr)
{
    camera_ptr = c_ptr;
}


ShadeInfo World::hit_objects(const Ray &ray)
{
    ShadeInfo closest(*this);
    closest.hit = false;

    ShadeInfo current(*this);

    float t = 0;

    for(unsigned int i = 0; i < geometry.size(); i++)
    {
        if (geometry[i]->hit(ray, t, current) == true)
        {
            if ( ( closest.hit == false ) || ( current.t < closest.t ) )
            {
                closest = ShadeInfo(current);
                current = ShadeInfo(*this);
            }
        }
    }

    return closest;
}