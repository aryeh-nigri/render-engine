#if !defined(SPHERE_H)
#define SPHERE_H

#include "RadialGeometry.h"

class Sphere : public RadialGeometry
{
  private:
    Point3D _center;

  public:
    Sphere() {}
    Sphere(const Point3D &p, double r) : _center(Point3D(p)), RadialGeometry(r) {}
    Sphere(double r, const Point3D &p) : RadialGeometry(r), _center(Point3D(p)) {}
    Sphere(const Sphere &s) : RadialGeometry(s), _center(s.getCenter()) {}

    Point3D getCenter() const;
    void setCenter(const Point3D &);

    std::list<Point3D> findIntersections(const Ray &) const;
    Vector getNormal(const Point3D &) const;
};

Point3D Sphere::getCenter() const
{
    return Point3D(this->_center);
}
void Sphere::setCenter(const Point3D &p)
{
    this->_center = Point3D(p);
}

std::list<Point3D> Sphere::findIntersections(const Ray &ray) const
{
    //Ray: P = P0 + tV
    //Sphere: |P - O|2 - r2 = 0

    //L = O - P0
    Vector L = Vector(ray.getPOO(), this->_center);

    //tm = L ・V
    double tm = L.dotProduct(ray.getDirection());

    //d = (|L|2 - tm2)0.5
    double d = sqrt(pow(L.length(), 2) - pow(tm, 2));

    //if d > r -> no intersections
    if (d > this->getRadius())
    {
        // Empty list
        return std::list<Point3D>(0);
    }

    std::list<Point3D> intersectionPoints;

    //th = (r2 - d2)0.5
    double th = sqrt(pow(this->getRadius(), 2) - pow(d, 2));

    //t1 = tm - th
    double t1 = tm - th;

    //t2 = tm + th
    double t2 = tm + th;

    //P1 = P0 + t1V
    //P2 = P0 + t2V
    //take only t > 0
    if (t1 > 0)
    {
        Point3D P1 = ray.getPOO() + (ray.getDirection() * t1).getHead();
        intersectionPoints.push_front(P1);
    }

    if (t2 > 0)
    {
        Point3D P2 = ray.getPOO() + (ray.getDirection() * t2).getHead();
        intersectionPoints.push_front(P2);
    }

    return intersectionPoints;
}

Vector Sphere::getNormal(const Point3D &point) const
{
    //V = P- O
    //N = V / ||V||
    Vector n = Vector(this->_center, point);
    n.normalize();

    return n;
}

std::ostream &operator<<(std::ostream &os, const Sphere &s)
{
    return os << "Sphere{ center = " << s.getCenter() << ", radius = " << s.getRadius() << "}";
}

#endif // SPHERE_H
