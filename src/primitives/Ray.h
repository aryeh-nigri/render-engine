#if !defined(RAY_H)
#define RAY_H

#include "Vector.h"

class Ray
{
  private:
    Point3D _POO;
    Vector _direction;

  public:
    Ray() {}
    Ray(const Point3D &p, const Vector &v) : _POO(Point3D(p)), _direction(Vector(v)) {}
    Ray(const Vector &v, const Point3D &p) : _direction(Vector(v)), _POO(Point3D(p)) {}
    Ray(const Ray &r) : _POO(r.getPOO()), _direction(r.getDirection()) {}

    Point3D getPOO() const;
    void setPOO(const Point3D &);
    Vector getDirection() const;
    void setDirection(const Vector &);

    Ray operator+(const Point3D &) const;
    bool operator==(const Ray &) const;
};

Point3D Ray::getPOO() const
{
    return Point3D(this->_POO);
}
void Ray::setPOO(const Point3D &p)
{
    this->_POO = Point3D(p);
}

Vector Ray::getDirection() const
{
    return Vector(this->_direction);
}
void Ray::setDirection(const Vector &v)
{
    this->_direction = Vector(v);
}

Ray Ray::operator+(const Point3D &p) const
{
    return Ray(this->_POO + p, this->_direction);
}

bool Ray::operator==(const Ray &r) const
{
    return (this->_POO == r.getPOO() && this->_direction == r.getDirection());
}

std::ostream &operator<<(std::ostream &os, const Ray &r)
{
    return os << "Ray{ POO = " << r.getPOO() << ", direction = " << r.getDirection() << "}";
}

#endif // RAY_H
