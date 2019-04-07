#if !defined(CAMERA_H)
#define CAMERA_H

#include "../primitives/Ray.h"

class Camera
{
  private:
    Point3D _P0;
    Vector _vUp;
    Vector _vTo;
    Vector _vRight;

    void setVRight();

  public:
    Camera() : _P0(Point3D()), _vUp(Vector(0.0, 1.0, 0.0)), _vTo(Vector(0.0, 0.0, -1.0)), _vRight(Vector(1.0, 0.0, 0.0)) {}
    Camera(const Point3D &p, const Vector &vUp, const Vector &vTo) : _P0(Point3D(p)), _vUp(Vector(vUp)), _vTo(Vector(vTo)), _vRight(vTo.crossProduct(vUp)) {}
    Camera(const Camera &c) : _P0(c.getP0()), _vUp(c.getVUp()), _vTo(c.getVTo()), _vRight(c.getVRight()) {}

    Point3D getP0() const;
    void setP0(const Point3D &);
    Vector getVUp() const;
    void setVUp(const Vector &);
    Vector getVTo() const;
    void setVTo(const Vector &);
    Vector getVRight() const;

    Ray constructRayThroughPixel(int, int, double, double, double, double, double);
};

Point3D Camera::getP0() const
{
    return Point3D(this->_P0);
}
void Camera::setP0(const Point3D &p)
{
    this->_P0 = Point3D(p);
}

Vector Camera::getVUp() const
{
    return Vector(this->_vUp);
}
void Camera::setVUp(const Vector &v)
{
    this->_vUp = Vector(v);
    this->setVRight();
}

Vector Camera::getVTo() const
{
    return Vector(this->_vTo);
}
void Camera::setVTo(const Vector &v)
{
    this->_vTo = Vector(v);
    this->setVRight();
}

Vector Camera::getVRight() const
{
    return Vector(this->_vRight);
}
void Camera::setVRight()
{
    this->_vRight = this->_vTo.crossProduct(this->_vUp);
}

Ray Camera::constructRayThroughPixel(int nX, int nY, double x, double y, double screenDistance, double screenWidth, double screenHeight)
{
    //  Image center
    //  Pc = P0 +dVto
    Point3D Pc = this->_P0 + (this->_vTo * screenDistance).getHead();

    //  Vright
    //  Vright = Vto x Vup
    this->setVRight();

    //  Ratio (pixel width)
    //  Rx = w/#Pixelsx
    //  Ry = h/#Pixelsy
    double Rx = screenWidth / nX;
    double Ry = screenHeight / nY;

    //   P = Pc + [[(x - nX/2)*Rx + Rx/2]*Vright - [(y - nY/2)*Ry + Ry/2]*Vup]
    double scalarRight = ((x - nX / 2.0) * Rx) + (Rx / 2.0);
    double scalarUp = ((y - nY / 2.0) * Ry) + (Ry / 2.0);

    Point3D P = Pc + ((this->_vRight * scalarRight) - (this->_vUp * scalarUp)).getHead();

    Vector direction = Vector(this->_P0, P);
    direction.normalize();
    return Ray(P, direction);
}

std::ostream &operator<<(std::ostream &os, const Camera &c)
{
    return os << "Camera{P0 = " << c.getP0() << ", vUp = " << c.getVUp() << ", vTo = " << c.getVTo() << ", vRight = " << c.getVRight() << "}";
}

#endif // CAMERA_H
