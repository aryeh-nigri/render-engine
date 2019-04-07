#if !defined(RADIALGEOMETRY_H)
#define RADIALGEOMETRY_H

#include "Geometry.h"

class RadialGeometry
{
  private:
    double _radius;

  public:
    RadialGeometry() : _radius(0.0) {}
    RadialGeometry(double r) { this->setRadius(r); }
    RadialGeometry(const RadialGeometry &rg) : _radius(rg.getRadius()) {}

    double getRadius() const;
    void setRadius(double);
};

double RadialGeometry::getRadius() const
{
    return this->_radius;
}
void RadialGeometry::setRadius(double r)
{
    if (r <= 0.0)
    {
        this->_radius = 0.0;
    }
    else
    {
        this->_radius = r;
    }
}

#endif // RADIALGEOMETRY_H
