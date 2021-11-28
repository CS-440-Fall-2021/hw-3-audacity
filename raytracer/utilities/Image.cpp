#include "Image.hpp"
#include "RGBColor.hpp"
#include "../world/ViewPlane.hpp"

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
    int r,g,b;
    
    r = (int) round(color.r * 255);
    g = (int) round(color.g * 255);
    b = (int) round(color.b * 255);

    colors[y][x] = RGBColor(r, g, b);
}


void Image::write_ppm(std::string path) const
{
    // Removes if ppm already exists
    remove(&path[0]);

    std::ofstream fp;
    fp.open(path);

    // Writes headers
    fp << "P3\n";
    fp << hres << " " << vres << std::endl;
    fp << "255\n";

    // Writes pixel r,g,b values
    for(int i = 0; i < hres; i++)
    {
        for(int j = 0; j < vres; j++)
        {
            fp << std::to_string(colors[i][j].r) + " " + std::to_string(colors[i][j].g) + " " + std::to_string(colors[i][j].b);

            if (j != (vres - 1))
                fp << " ";
        }

        fp << "\n";
    }

    fp.close();
}