#if !defined(RAY_H)
#define RAY_H

#include "Vector.h"

class Ray
{
  private:
    Point3D POO;
    Vector direction;

  public:
    Ray() {}
    Ray(const Point3D &p, const Vector &v) : POO(Point3D(p)), direction(Vector(v)) {}
    Ray(const Vector &v, const Point3D &p) : direction(Vector(v)), POO(Point3D(p)) {}
    Ray(const Ray &r) : POO(r.getPOO()), direction(r.getDirection()) {}

    Point3D getPOO() const;
    void setPOO(const Point3D &);
    Vector getDirection() const;
    void setDirection(const Vector &);

    Ray operator+(const Point3D &) const;
    bool operator==(const Ray &) const;
};

Point3D Ray::getPOO() const
{
    // return this->POO;
    return Point3D(this->POO);
}
void Ray::setPOO(const Point3D &p)
{
    // this->POO = p;
    this->POO = Point3D(p);
}

Vector Ray::getDirection() const
{
    return Vector(this->direction);
}
void Ray::setDirection(const Vector &v)
{
    this->direction = Vector(v);
}

Ray Ray::operator+(const Point3D &p) const
{
    return Ray(this->POO + p, this->direction);
}

bool Ray::operator==(const Ray &r) const
{
    return (this->POO == r.getPOO() && this->direction == r.getDirection());
}

std::ostream &operator<<(std::ostream &os, const Ray &r)
{
    return os << "Ray{POO = " << r.getPOO() << ", direction = " << r.getDirection() << "}";
}

#endif // RAY_H
