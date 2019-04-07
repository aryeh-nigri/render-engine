#if !defined(GEOMETRY_H)
#define GEOMETRY_H

#include "../primitives/Material.h"
#include "../primitives/Ray.h"
#include "../helper/Color.h"
#include <list>

class Geometry
{
  private:
    Material _material;
    Color _emission;
    int _nShininess;

  public:
    Geometry() : _material(Material()), _emission(Color::BLACK), _nShininess(1) {}
    Geometry(const Geometry &g) : _material(g.getMaterial()), _emission(g.getEmission()), _nShininess(g.getNShininess()) {}

    Material getMaterial() const;
    void setMaterial(const Material &);
    Color getEmission() const;
    void setEmission(const Color &);
    int getNShininess() const;
    void setNShininess(int);

    // Find all intersections that a Ray makes with a Geometry.
    virtual std::list<Point3D> findIntersections(const Ray &) const = 0;
    // Get the normal Vector of a Geometry.
    virtual Vector getNormal(const Point3D &) const = 0;
};

Material Geometry::getMaterial() const
{
    return Material(this->_material);
}
void Geometry::setMaterial(const Material &m)
{
    this->_material = Material(m);
}

Color Geometry::getEmission() const
{
    return Color(this->_emission);
}
void Geometry::setEmission(const Color &c)
{
    this->_emission = (Color(c));
}

int Geometry::getNShininess() const
{
    return this->_nShininess;
}
void Geometry::setNShininess(int n)
{
    if (n <= 0)
    {
        this->_nShininess = 0;
    }
    else
    {
        this->_nShininess = n;
    }
}

#endif // GEOMETRY_H
