#if !defined(POINT2D_H)
#define POINT2D_H

#include "Coordinate.h"

class Point2D
{
  protected:
    Coordinate x;
    Coordinate y;

  public:
    Point2D() {}
    Point2D(double u, double v) : x(Coordinate(u)), y(Coordinate(v)) {}
    Point2D(Coordinate a, Coordinate b) : x(Coordinate(a)), y(Coordinate(b)) {}
    Point2D(const Point2D &p) : x(p.getX()), y(p.getY()) {}

    Coordinate getX() const;
    void setX(const Coordinate &);
    Coordinate getY() const;
    void setY(const Coordinate &);

    bool operator==(const Point2D &) const;
    bool operator>(const Point2D &) const;
    bool operator<(const Point2D &) const;
};

Coordinate Point2D::getX() const
{
    // return this->x;
    return Coordinate(this->x);
}
void Point2D::setX(const Coordinate &a)
{
    this->x = a;
}
Coordinate Point2D::getY() const
{
    // return this->y;
    return Coordinate(this->y);
}
void Point2D::setY(const Coordinate &b)
{
    this->y = b;
}

bool Point2D::operator==(const Point2D &p) const
{
    return (this->x == p.getX() && this->y == p.getY());
}

bool Point2D::operator>(const Point2D &p) const
{
    return (this->x > p.getX() && this->y > p.getY());
}
bool Point2D::operator<(const Point2D &p) const
{
    return (this->x < p.getX() && this->y < p.getY());
}

std::ostream &operator<<(std::ostream &os, const Point2D &p)
{
    return os << "Point2D{x = " << p.getX() << ", y = " << p.getY() << "}";
}

#endif // POINT2D_H