#if !defined(PLANE_H)
#define PLANE_H

#include "Geometry.h"
#include "FlatGeometry.h"

class Plane : public Geometry, public FlatGeometry
{
  private:
    Vector _N;
    Point3D _Q;

  public:
    Plane() {}
    Plane(const Vector &v, const Point3D &p) : _N(Vector(v)), _Q(Point3D(p)) { this->_N.normalize(); }
    Plane(const Point3D &p, const Vector &v) : _Q(Point3D(p)), _N(Vector(v)) { this->_N.normalize(); }
    Plane(const Plane &p) : _N(p.getN()), _Q(p.getQ()) {}

    Vector getN() const;
    void setN(const Vector &);
    Point3D getQ() const;
    void setQ(const Point3D &);

    std::list<Point3D> findIntersections(const Ray &) const;
    Vector getNormal(const Point3D &) const;
};

Vector Plane::getN() const
{
    return Vector(this->_N);
}
void Plane::setN(const Vector &v)
{
    this->_N = Vector(v);
}

Point3D Plane::getQ() const
{
    return Point3D(this->_Q);
}
void Plane::setQ(const Point3D &p)
{
    this->_Q = Point3D(p);
}

std::list<Point3D> Plane::findIntersections(const Ray &ray) const
{
    //Ray: P = P0 + tV
    //Plane: N・(P - Q0) = 0
    //N・(P0 + tV - Q0) = 0
    //t = - N・(P0 - Q0)/(N・V)

    std::list<Point3D> intersectionPoints;

    Vector vectorAtPlane = Vector(this->_Q, ray.getPOO());

    double vectorsProduct = this->_N.dotProduct(ray.getDirection());

    if (vectorsProduct != 0.0)
    {
        double t = -1.0 * (this->_N.dotProduct(vectorAtPlane) / vectorsProduct);
        if (t > 0.0)
        {
            Point3D point = (ray.getPOO() + (ray.getDirection() * t).getHead());
            intersectionPoints.push_front(point);
        }
    }

    return intersectionPoints;
}

Vector Plane::getNormal(const Point3D &point) const
{
    return Vector(this->_N);
}

std::ostream &operator<<(std::ostream &os, const Plane &p)
{
    return os << "Plane{N = " << p.getN() << ", Q = " << p.getQ() << "}";
}

#endif // PLANE_H
