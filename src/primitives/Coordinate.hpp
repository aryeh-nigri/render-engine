#if !defined(COORDINATE_HPP)
#define COORDINATE_HPP

#include <iostream>

class Coordinate
{
  private:
    double _coordinate;

  public:
    Coordinate() : _coordinate(0.0) {}
    Coordinate(double c) : _coordinate(c) {}
    Coordinate(const Coordinate &c) : _coordinate(c.getCoordinate()) {}

    double getCoordinate() const;
    void setCoordinate(double);

    Coordinate operator+(const Coordinate &) const;
    Coordinate operator-(const Coordinate &) const;
    double operator*(const Coordinate &)const;
    double operator/(double) const;
    bool operator==(const Coordinate &) const;
    bool operator>(const Coordinate &) const;
    bool operator<(const Coordinate &) const;
};

double Coordinate::getCoordinate() const
{
    return this->_coordinate;
}

void Coordinate::setCoordinate(double c)
{
    this->_coordinate = c;
}

Coordinate Coordinate::operator+(const Coordinate &c) const
{
    return Coordinate(this->_coordinate + c.getCoordinate());
}

Coordinate Coordinate::operator-(const Coordinate &c) const
{
    return Coordinate(this->_coordinate - c.getCoordinate());
}

double Coordinate::operator*(const Coordinate &c) const
{
    return this->_coordinate * c.getCoordinate();
}

double Coordinate::operator/(double k) const
{
    return this->_coordinate / k;
}

bool Coordinate::operator==(const Coordinate &c) const
{
    return (this->_coordinate == c.getCoordinate());
}

bool Coordinate::operator>(const Coordinate &c) const
{
    return (this->_coordinate > c.getCoordinate());
}
bool Coordinate::operator<(const Coordinate &c) const
{
    return (this->_coordinate < c.getCoordinate());
}

std::ostream &operator<<(std::ostream &os, const Coordinate &c)
{
    return os << "Coordinate{ coordinate = " << c.getCoordinate() << "}";
}

#endif // COORDINATE_HPP
