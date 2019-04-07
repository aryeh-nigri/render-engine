#if !defined(MATERIAL_H)
#define MATERIAL_H

#include <iostream>

class Material
{
  private:
    double _Kd; //   Diffusion attenuation coefficient
    double _Ks; //   Specular attenuation coefficient
    double _Kr; //   Reflection coefficient (1 for mirror)
    double _Kt; //   Refraction coefficient (1 for transparent)
    double _n;  //   Refraction index

  public:
    Material() : _Kd(1.0), _Ks(1.0), _Kr(0.0), _Kt(0.0), _n(1.0) {}
    Material(double kd, double ks, double kr, double kt, double n) : _Kd(kd), _Ks(ks), _Kr(kr), _Kt(kt), _n(n) {}
    Material(const Material &m) : _Kd(m.getKd()), _Ks(m.getKs()), _Kr(m.getKr()), _Kt(m.getKt()), _n(m.getN()) {}

    double getKd() const;
    void setKd(double);
    double getKs() const;
    void setKs(double);
    double getKr() const;
    void setKr(double);
    double getKt() const;
    void setKt(double);
    double getN() const;
    void setN(double);
};

double Material::getKd() const
{
    return this->_Kd;
}
void Material::setKd(double kd)
{
    if (kd >= 1.0)
    {
        this->_Kd = 1.0;
    }
    else if (kd <= 0.0)
    {
        this->_Kd = 0.0;
    }
    else
    {
        this->_Kd = kd;
    }
}

double Material::getKs() const
{
    return this->_Ks;
}
void Material::setKs(double ks)
{
    if (ks >= 1.0)
    {
        this->_Ks = 1.0;
    }
    else if (ks <= 0.0)
    {
        this->_Ks = 0.0;
    }
    else
    {
        this->_Ks = ks;
    }
}

double Material::getKr() const
{
    return this->_Kr;
}
void Material::setKr(double kr)
{
    if (kr >= 1.0)
    {
        this->_Kr = 1.0;
    }
    else if (kr <= 0.0)
    {
        this->_Kr = 0.0;
    }
    else
    {
        this->_Kr = kr;
    }
}

double Material::getKt() const
{
    return this->_Kt;
}
void Material::setKt(double kt)
{
    if (kt >= 1.0)
    {
        this->_Kt = 1.0;
    }
    else if (kt <= 0.0)
    {
        this->_Kt = 0.0;
    }
    else
    {
        this->_Kt = kt;
    }
}

double Material::getN() const
{
    return this->_n;
}
void Material::setN(double n)
{
    if (n <= 0.0)
    {
        this->_n = 0.0;
    }
    else
    {
        this->_n = n;
    }
}

std::ostream &operator<<(std::ostream &os, const Material &m)
{
    return os << "Material{ Kd = " << m.getKd() << ", Ks = " << m.getKs() << ", Kr = " << m.getKr() << ", Kt = " << m.getKt() << ", n = " << m.getN() << "}";
}

#endif // MATERIAL_H