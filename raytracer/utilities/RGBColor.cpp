#include "RGBColor.hpp"

RGBColor::RGBColor()
{
    r = g = b = 0;
}

RGBColor::RGBColor(float c)
{
    r = g = b = c;
}

RGBColor::RGBColor(float _r, float _g, float _b)
{
    r = _r;
    g = _g;
    b = _b;
}

std::string RGBColor::to_string() const
{
    std::string r_s = std::to_string((int)round(r * 255));
    std::string g_s = std::to_string((int)round(g * 255));
    std::string b_s = std::to_string((int)round(b * 255));

    return "RGBColor: " + r_s + " " + g_s + " " + b_s + "\n";
}


RGBColor RGBColor::operator+(const RGBColor &c) const
{
    return RGBColor(r + c.r, g + c.g, b + c.b);
}

RGBColor &RGBColor::operator+=(const RGBColor &c)
{
    r += c.r;
    g += c.g;
    b += c.b;

    return *this;
}

RGBColor RGBColor::operator*(const float a) const
{
    return RGBColor(r * a, g * a, b * a);
}

RGBColor &RGBColor::operator*=(const float a)
{
    r *= a;
    g *= a;
    b *= a;

    return *this;
}

RGBColor RGBColor::operator/(const float a) const
{
    return RGBColor(r / a, g / a, b / a);
}

RGBColor &RGBColor::operator/=(const float a)
{
    r /= a;
    g /= a;
    b /= a;

    return *this;
}


RGBColor RGBColor::operator*(const RGBColor &c) const
{
    return RGBColor(r * c.r, g * c.g, b * c.b);
}

bool RGBColor::operator==(const RGBColor &c) const
{
    if ((r == c.r)  && (g == c.g) && (b == c.b))
        return true;
    
    return false;
}

RGBColor RGBColor::powc(float p) const
{
    return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}

float RGBColor::average() const
{
    return (r + g + b) / 3;
}


RGBColor operator*(const float a, const RGBColor &c)
{
    return RGBColor(c.r * a, c.g * a, c.b * a);
}
