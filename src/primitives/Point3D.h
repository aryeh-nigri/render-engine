#if !defined(POINT3D_H)
#define POINT3D_H

#include "Point2D.h"
#include <math.h>

class Point3D : public Point2D
{
  private:
    Coordinate z;

  public:
    Point3D() {}
    Point3D(double u, double v, double w) : Point2D(u, v), z(Coordinate(w)) {}
    Point3D(const Coordinate &a, const Coordinate &b, const Coordinate &c) : Point2D(a, b), z(Coordinate(c)) {}
    Point3D(const Point3D &p) : Point2D(p), z(p.getZ()) {}

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
    return Coordinate(this->z);
}
void Point3D::setZ(const Coordinate &c)
{
    this->z = Coordinate(c);
}

Point3D Point3D::operator+(const Point3D &p) const
{
    return Point3D(
        this->x + p.getX(),
        this->y + p.getY(),
        this->z + p.getZ());
}

Point3D Point3D::operator-(const Point3D &p) const
{
    return Point3D(
        this->x - p.getX(),
        this->y - p.getY(),
        this->z - p.getZ());
}

Point3D Point3D::operator*(double k) const
{
    return Point3D(this->x * k, this->y * k, this->z * k);
}

Point3D Point3D::operator/(double k) const
{
    return Point3D(this->x / k, this->y / k, this->z / k);
}

double Point3D::operator*(const Point3D &p) const
{
    return this->x * p.getX() + this->y * p.getY() + this->z * p.getZ();
}

bool Point3D::operator==(const Point3D &p) const
{
    return (this->x == p.getX() && this->y == p.getY() && this->z == p.getZ());
}

bool Point3D::operator>(const Point3D &p) const
{
    return (this->x > p.getX() && this->y > p.getY() && this->z > p.getZ());
}
bool Point3D::operator<(const Point3D &p) const
{
    return (this->x < p.getX() && this->y < p.getY() && this->z < p.getZ());
}

double Point3D::distance(const Point3D &p) const
{
    //   d = sqrt( (x1-x2)^2 + (y1 - y2)^2 + (z1 - z2)^2 )
    double x0 = pow((this->x - p.getX()).getCoordinate(), 2);
    double y0 = pow((this->y - p.getY()).getCoordinate(), 2);
    double z0 = pow((this->z - p.getZ()).getCoordinate(), 2);

    return sqrt(x0 + y0 + z0);
}

std::ostream &operator<<(std::ostream &os, const Point3D &p)
{
    return os << "Point3D{x = " << p.getX() << ", y = " << p.getY() << ", z = " << p.getZ() << "}";
}

#endif // POINT3D_H
