#if !defined(COORDINATE_H)
#define COORDINATE_H

#include <iostream>

class Coordinate
{
  private:
    double coordinate;

  public:
    Coordinate() : coordinate(0.0) {}
    Coordinate(double c) : coordinate(c) {}
    Coordinate(const Coordinate &c) : coordinate(c.getCoordinate()) {}

    double getCoordinate() const;
    void setCoordinate(double);

    Coordinate operator+(const Coordinate &) const;
    Coordinate operator-(const Coordinate &) const;
    double operator*(const Coordinate &) const;
    double operator/(double) const;
    bool operator==(const Coordinate &) const;
    bool operator>(const Coordinate &) const;
    bool operator<(const Coordinate &) const;
};

double Coordinate::getCoordinate() const
{
    return this->coordinate;
}

void Coordinate::setCoordinate(double c)
{
    this->coordinate = c;
}

Coordinate Coordinate::operator+(const Coordinate &c) const
{
    return Coordinate(this->coordinate + c.coordinate);
}

Coordinate Coordinate::operator-(const Coordinate &c) const
{
    return Coordinate(this->coordinate - c.coordinate);
}

double Coordinate::operator*(const Coordinate &c) const
{
    return this->coordinate * c.coordinate;
}

double Coordinate::operator/(double k) const
{
    return this->coordinate / k;
}

bool Coordinate::operator==(const Coordinate &c) const
{
    return (this->coordinate == c.coordinate);
}

bool Coordinate::operator>(const Coordinate &c) const
{
    return (this->coordinate > c.coordinate);
}
bool Coordinate::operator<(const Coordinate &c) const
{
    return (this->coordinate < c.coordinate);
}

std::ostream &operator<<(std::ostream &os, const Coordinate &c)
{
    return os << "Coordinate{coordinate = " << c.getCoordinate() << "}";
}

#endif // COORDINATE_H
