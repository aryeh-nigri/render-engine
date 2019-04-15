#if !defined(POINT2D_HPP)
#define POINT2D_HPP

#include "./Coordinate.hpp"

class Point2D
{
  private:
    Coordinate _x;
    Coordinate _y;

  public:
    Point2D() {}
    Point2D(double u, double v) : _x(Coordinate(u)), _y(Coordinate(v)) {}
    Point2D(Coordinate a, Coordinate b) : _x(Coordinate(a)), _y(Coordinate(b)) {}
    Point2D(const Point2D &p) : _x(p.getX()), _y(p.getY()) {}

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
    return Coordinate(this->_x);
}
void Point2D::setX(const Coordinate &c)
{
    this->_x = Coordinate(c);
}
Coordinate Point2D::getY() const
{
    return Coordinate(this->_y);
}
void Point2D::setY(const Coordinate &c)
{
    this->_y = Coordinate(c);
}

bool Point2D::operator==(const Point2D &p) const
{
    return (this->_x == p.getX() && this->_y == p.getY());
}

bool Point2D::operator>(const Point2D &p) const
{
    return (this->_x > p.getX() && this->_y > p.getY());
}
bool Point2D::operator<(const Point2D &p) const
{
    return (this->_x < p.getX() && this->_y < p.getY());
}

std::ostream &operator<<(std::ostream &os, const Point2D &p)
{
    return os << "Point2D{ X = " << p.getX() << ", Y = " << p.getY() << "}";
}

#endif // POINT2D_HPP