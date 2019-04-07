#if !defined(MATERIAL_H)
#define MATERIAL_H

#include <iostream>

class Material
{
  private:
    double Kd; //   Diffusion attenuation coefficient
    double Ks; //   Specular attenuation coefficient
    double Kr; //   Reflection coefficient (1 for mirror)
    double Kt; //   Refraction coefficient (1 for transparent)
    double n;  //   Refraction index

  public:
    Material() : Kd(1.0), Ks(1.0), Kr(0.0), Kt(0.0), n(1.0) {}
    Material(double kd, double ks, double kr, double kt, double m) : Kd(kd), Ks(ks), Kr(kr), Kt(kt), n(m) {}
    Material(const Material &m) : Kd(m.getKd()), Ks(m.getKs()), Kr(m.getKr()), Kt(m.getKt()), n(m.getN()) {}

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
    return this->Kd;
}
void Material::setKd(double kd)
{
    if (kd > 1.0)
    {
        this->Kd = 1.0;
    }
    else if (kd <= 0.0)
    {
        this->Kd = 0.0;
    }
    else
    {
        this->Kd = kd;
    }
}

double Material::getKs() const
{
    return this->Ks;
}
void Material::setKs(double ks)
{
    if (ks > 1.0)
    {
        this->Ks = 1.0;
    }
    else if (ks <= 0.0)
    {
        this->Ks = 0.0;
    }
    else
    {
        this->Ks = ks;
    }
}

double Material::getKr() const
{
    return this->Kr;
}
void Material::setKr(double kr)
{
    if (kr > 1.0)
    {
        this->Kr = 1.0;
    }
    else if (kr <= 0.0)
    {
        this->Kr = 0.0;
    }
    else
    {
        this->Kr = kr;
    }
}

double Material::getKt() const
{
    return this->Kt;
}
void Material::setKt(double kt)
{
    if (kt > 1.0)
    {
        this->Kt = 1.0;
    }
    else if (kt <= 0.0)
    {
        this->Kt = 0.0;
    }
    else
    {
        this->Kt = kt;
    }
}

double Material::getN() const
{
    return this->n;
}
void Material::setN(double m)
{
    if (m <= 0.0)
    {
        this->n = 0.0;
    }
    else
    {
        this->n = m;
    }
}

std::ostream &operator<<(std::ostream &os, const Material &m)
{
    return os << "Material{Kd = " << m.getKd() << ", Ks = " << m.getKs() << ", Kr = " << m.getKr() << ", Kt = " << m.getKt() << ", n = " << m.getN() << "}";
}

#endif // MATERIAL_H