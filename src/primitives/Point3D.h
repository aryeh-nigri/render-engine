#if !defined(POINT3D_H)
#define POINT3D_H

#include "Point2D.h"
#include <math.h>

class Point3D : public Point2D
{
  private:
    Coordinate _z;

  public:
    Point3D() {}
    Point3D(double u, double v, double w) : Point2D(u, v), _z(Coordinate(w)) {}
    Point3D(const Coordinate &a, const Coordinate &b, const Coordinate &c) : Point2D(a, b), _z(Coordinate(c)) {}
    Point3D(const Point3D &p) : Point2D(p), _z(p.getZ()) {}

    Coordinate getZ() const;
    void setZ(const Coordinate &);

    Point3D operator+(const Point3D &) const;
    Point3D operator-(const Point3D &) const;
    Point3D operator*(double)const;
    Point3D operator/(double) const;
    double operator*(const Point3D &)const;
    bool operator==(const Point3D &) const;
    bool operator>(const Point3D &) const;
    bool operator<(const Point3D &) const;

    double distance(const Point3D &) const;
};

Coordinate Point3D::getZ() const
{
    return Coordinate(this->_z);
}
void Point3D::setZ(const Coordinate &c)
{
    this->_z = Coordinate(c);
}

Point3D Point3D::operator+(const Point3D &p) const
{
    return Point3D(
        this->getX() + p.getX(),
        this->getY() + p.getY(),
        this->_z + p.getZ());
}

Point3D Point3D::operator-(const Point3D &p) const
{
    return Point3D(
        this->getX() - p.getX(),
        this->getY() - p.getY(),
        this->_z - p.getZ());
}

Point3D Point3D::operator*(double k) const
{
    return Point3D(this->getX() * k, this->getY() * k, this->_z * k);
}

Point3D Point3D::operator/(double k) const
{
    return Point3D(this->getX() / k, this->getY() / k, this->_z / k);
}

double Point3D::operator*(const Point3D &p) const
{
    return this->getX() * p.getX() + this->getY() * p.getY() + this->_z * p.getZ();
}

bool Point3D::operator==(const Point3D &p) const
{
    return (this->getX() == p.getX() && this->getY() == p.getY() && this->_z == p.getZ());
}

bool Point3D::operator>(const Point3D &p) const
{
    return (this->getX() > p.getX() && this->getY() > p.getY() && this->_z > p.getZ());
}
bool Point3D::operator<(const Point3D &p) const
{
    return (this->getX() < p.getX() && this->getY() < p.getY() && this->_z < p.getZ());
}

double Point3D::distance(const Point3D &p) const
{
    //   d = sqrt( (x1-x2)^2 + (y1 - y2)^2 + (z1 - z2)^2 )
    double x0 = pow((this->getX() - p.getX()).getCoordinate(), 2);
    double y0 = pow((this->getY() - p.getY()).getCoordinate(), 2);
    double z0 = pow((this->_z - p.getZ()).getCoordinate(), 2);

    return sqrt(x0 + y0 + z0);
}

std::ostream &operator<<(std::ostream &os, const Point3D &p)
{
    return os << "Point3D{ X = " << p.getX() << ", Y = " << p.getY() << ", Z = " << p.getZ() << "}";
}

#endif // POINT3D_H
