#if !defined(VECTOR_H)
#define VECTOR_H

#include "Point3D.h"

class Vector
{
  private:
    Point3D _head;

  public:
    Vector() {}
    Vector(double u, double v, double w) : _head(Point3D(u, v, w)) {}
    Vector(const Point3D &p) : _head(Point3D(p)) {}
    Vector(const Point3D &start, const Point3D &end) : _head(Point3D(end - start)) {}
    Vector(const Vector &v) : _head(v.getHead()) {}

    Point3D getHead() const;
    void setHead(const Point3D &);

    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;
    Vector operator*(double)const;         // scaling
    double operator*(const Vector &)const; // dot product
    double dotProduct(const Vector &) const;
    Vector crossProduct(const Vector &) const; // cross product
    bool operator==(const Vector &) const;
    bool operator>(const Vector &) const;
    bool operator<(const Vector &) const;

    double length() const;
    void normalize();
};

Point3D Vector::getHead() const
{
    // return this->_head;
    return Point3D(this->_head);
}

void Vector::setHead(const Point3D &p)
{
    this->_head = p;
}

Vector Vector::operator+(const Vector &v) const
{
    return Vector(this->_head + v.getHead());
}

Vector Vector::operator-(const Vector &v) const
{
    return Vector(this->_head - v.getHead());
}

Vector Vector::operator*(double scalar) const // scaling
{
    //   v * a = (v1*a)i + (v2*a)j + (v3*a)k
    return Vector(this->_head * scalar);
}

double Vector::operator*(const Vector &v) const // dot product
{
    //   u*v = u1*v1 + u2*v2 + u3*v3   ;   a scalar is returned
    return this->_head * v.getHead();
}

double Vector::dotProduct(const Vector &v) const
{
    return this->operator*(v);
}

Vector Vector::crossProduct(const Vector &v) const // cross product
{
    //   u = u1 + u2 + u3   ;   v = v1 + v2 + v3
    //   u X v = (u2*v3 - u3*v2)i + (u3*v1 - u1*v3)j + (u1*v2 - u2*v1)k   ;   a new Vector is returned
    return Vector(
        Point3D(
            (this->_head.getY() * v.getHead().getZ()) - (this->_head.getZ() * v.getHead().getY()),
            (this->_head.getZ() * v.getHead().getX()) - (this->_head.getX() * v.getHead().getZ()),
            (this->_head.getX() * v.getHead().getY()) - (this->_head.getY() * v.getHead().getX())));
}

bool Vector::operator==(const Vector &v) const
{
    return this->_head == v.getHead();
}

bool Vector::operator>(const Vector &v) const
{
    return this->_head > v.getHead();
}

bool Vector::operator<(const Vector &v) const
{
    return this->_head < v.getHead();
}

double Vector::length() const
{
    //   |v| = sqrt(v1^2 + v2^2 + v3^2)
    double v1 = pow(this->_head.getX().getCoordinate(), 2);
    double v2 = pow(this->_head.getY().getCoordinate(), 2);
    double v3 = pow(this->_head.getZ().getCoordinate(), 2);

    return sqrt(v1 + v2 + v3);
}

void Vector::normalize()
{
    //   the normal Vector is the Vector itself divided by its length
    //   making a new Vector with a length of 1
    double length = this->length();

    if (length == 0.0 || length == 1.0)
    {
        return;
    }

    this->_head = this->_head / length;
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    return os << "Vector{ head = " << v.getHead() << "}";
}

#endif // VECTOR_H
