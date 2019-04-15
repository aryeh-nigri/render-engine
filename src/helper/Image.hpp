#if !defined(IMAGE_HPP)
#define IMAGE_HPP

#include "./Color.hpp"

class Image
{
private:
public:
  virtual void setRGB(int, int, const Color &) = 0;
  virtual void write(std::string) const = 0;
};

#endif // IMAGE_HPP
