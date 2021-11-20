#include "Image.hpp"
#include "RGBColor.hpp"
#include "ViewPlane.hpp"

Image::Image(int _hres, int _vres)
{
    hres = _hres;
    vres = _vres;

    colors = new RGBColor *[vres];

    for(int i = 0; i < vres; i++)
    {
        colors[i] = new RGBColor[hres];
    }
}

Image::Image(const ViewPlane &vp)
{
    hres = vp.get_hres();
    vres = vp.get_vres();

    colors = new RGBColor *[vres];

    for(int i = 0; i < vres; i++)
    {
        colors[i] = new RGBColor[hres];
    }
}

Image::~Image()
{
    for(int i = 0; i < vres; i++)
    {
        delete colors[i];
    }

    delete colors;
}


void Image::set_pixel(int x, int y, const RGBColor& color)
{
    colors[y][x] = color;
}


void Image::write_ppm(std::string path) const
{
    // Will do later
}