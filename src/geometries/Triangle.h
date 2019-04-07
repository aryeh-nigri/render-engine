#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include "Geometry.h"
#include "FlatGeometry.h"
#include "Plane.h"

class Triangle : public Geometry, public FlatGeometry
{
  private:
    Point3D _p1;
    Point3D _p2;
    Point3D _p3;

  public:
    Triangle() {}
    Triangle(const Point3D &p1, const Point3D &p2, const Point3D &p3) : _p1(p1), _p2(p2), _p3(p3) {}
    Triangle(const Triangle &t) : Geometry(), _p1(t.getP1()), _p2(t.getP2()), _p3(t.getP3()) {}

    Point3D getP1() const;
    void setP1(const Point3D &);
    Point3D getP2() const;
    void setP2(const Point3D &);
    Point3D getP3() const;
    void setP3(const Point3D &);

    std::list<Point3D> findIntersections(const Ray &) const;
    Vector getNormal(const Point3D &) const;
};

Point3D Triangle::getP1() const
{
    return Point3D(this->_p1);
}
void Triangle::setP1(const Point3D &p)
{
    this->_p1 = Point3D(p);
}

Point3D Triangle::getP2() const
{
    return Point3D(this->_p2);
}
void Triangle::setP2(const Point3D &p)
{
    this->_p1 = Point3D(p);
}

Point3D Triangle::getP3() const
{
    return Point3D(this->_p3);
}
void Triangle::setP3(const Point3D &p)
{
    this->_p1 = Point3D(p);
}

std::list<Point3D> Triangle::findIntersections(const Ray &ray) const
{
    //For each side of the triangle:
    //V1=T1-P0
    //V2=T2-P0
    //N1=(V2xV1)/|V2xV1|
    //Then,
    //if sign((P-P0)・N1) ==
    //sign((P-P0)・N2) ==
    //sign((P-P0)・N3)
    //-> return true

    Vector normal = this->getNormal(this->_p1);

    Plane planeTriangle = Plane(normal, this->_p1);

    std::list<Point3D> planeTrianglePoints = planeTriangle.findIntersections(ray);

    if (planeTrianglePoints.empty())
    {
        // Empty list
        return std::list<Point3D>(0);
    }

    Point3D point = planeTrianglePoints.front();

    Vector v1 = Vector(ray.getPOO(), this->_p1);
    Vector v2 = Vector(ray.getPOO(), this->_p2);
    Vector v3 = Vector(ray.getPOO(), this->_p3);

    Vector n1 = v2.crossProduct(v1);
    n1.normalize();
    Vector n2 = v1.crossProduct(v3);
    n2.normalize();
    Vector n3 = v3.crossProduct(v2);
    n3.normalize();

    // Point - POO
    Vector POO_To_Point = Vector(ray.getPOO(), point);

    double d1 = POO_To_Point.dotProduct(n1);
    double d2 = POO_To_Point.dotProduct(n2);
    double d3 = POO_To_Point.dotProduct(n3);

    int sign_d1 = d1 > 0.0 ? 1 : (d1 < 0.0 ? -1 : d1);
    int sign_d2 = d2 > 0.0 ? 1 : (d2 < 0.0 ? -1 : d2);
    int sign_d3 = d3 > 0.0 ? 1 : (d3 < 0.0 ? -1 : d3);

    if (sign_d1 == sign_d2 && sign_d2 == sign_d3)
    {
        return planeTrianglePoints;
    }
    else
    {
        // Empty list
        return std::list<Point3D>(0);
    }
}

Vector Triangle::getNormal(const Point3D &point) const
{
    //V1 = P2 - P1
    //V2 = P3 - P1
    //N = ( V1 x V2 ) / || V1 x V2 ||

    Vector v1 = Vector(this->_p1, this->_p2);
    Vector v2 = Vector(this->_p1, this->_p3);
    Vector N = v1.crossProduct(v2);
    N.normalize();

    return N;
}

std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    return os << "Triangle{ P1 = " << t.getP1() << ", P2 = " << t.getP2() << ", P3 = " << t.getP3() << " }";
}

#endif // TRIANGLE_H
