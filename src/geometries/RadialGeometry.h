#if !defined(RADIALGEOMETRY_H)
#define RADIALGEOMETRY_H

#include "Geometry.h"

class RadialGeometry
{
  private:
    double radius;

  public:
    RadialGeometry() : radius(0.0) {}
    RadialGeometry(double r) { this->setRadius(r); }
    RadialGeometry(const RadialGeometry &rg) : radius(rg.getRadius()) {}

    double getRadius() const;
    void setRadius(double);
};

double RadialGeometry::getRadius() const
{
    return this->radius;
}
void RadialGeometry::setRadius(double r)
{
    if (r < 0.0)
    {
        this->radius = 0.0;
    }
    else
    {
        this->radius = r;
    }
}

#endif // RADIALGEOMETRY_H
