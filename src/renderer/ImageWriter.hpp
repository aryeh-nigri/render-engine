#if !defined(IMAGEWRITER_HPP)
#define IMAGEWRITER_HPP

#include "../helper/Image.hpp"

const std::string IMAGES_PATH = "Samples/";

class ImageWriter
{
private:
  int _imageWidth{500};
  int _imageHeight{500};
  int _Nx{50};
  int _Ny{50};
  std::string _imageName{"default"};
  Image &_image;

public:
  ImageWriter(const char *imageName, int width, int height, int Ny, int Nx, Image &image) : _imageWidth(width), _imageHeight(height), _Nx(Nx),
                                                                                            _Ny(Ny), _imageName(imageName), _image(image) {}
  ImageWriter(const ImageWriter &iw) : _imageWidth(iw.getWidth()),
                                       _imageHeight(iw.getHeight()), _Nx(iw.getNx()),
                                       _Ny(iw.getNy()), _imageName(iw.getName()), _image(iw.getImage()) {}

  std::string getName() const;
  Image &getImage() const;
  int getWidth() const;
  int getHeight() const;
  int getNx() const;
  void setNx(int);
  int getNy() const;
  void setNy(int);

  void writeToImage() const;
  void writePixel(int, int, const Color &);
  void writePixel(int, int, int, int, int);
};

Image &ImageWriter::getImage() const { return this->_image; }
std::string ImageWriter::getName() const { return this->_imageName; }

int ImageWriter::getWidth() const { return this->_imageWidth; }
int ImageWriter::getHeight() const { return this->_imageHeight; }

int ImageWriter::getNx() const { return this->_Nx; }
void ImageWriter::setNx(int Nx) { this->_Nx = Nx; }

int ImageWriter::getNy() const { return this->_Ny; }
void ImageWriter::setNy(int Ny) { this->_Ny = Ny; }

void ImageWriter::writeToImage() const
{
  try
  {
    // this->_image.write(IMAGES_PATH + this->_imageName);
    this->_image.write(this->_imageName);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

void ImageWriter::writePixel(int xIndex, int yIndex, const Color &color)
{
  _image.setRGB(xIndex, yIndex, color);
}

void ImageWriter::writePixel(int xIndex, int yIndex, int r, int g, int b)
{
  this->writePixel(xIndex, yIndex, Color(r, g, b));
}

#endif // IMAGEWRITER_HPP
