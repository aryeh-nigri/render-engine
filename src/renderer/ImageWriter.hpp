#if !defined(IMAGEWRITER_HPP)
#define IMAGEWRITER_HPP

#include "../helper/BMPImage.hpp"

class ImageWriter
{
private:
  int _imageWidth{500};
  int _imageHeight{500};
  int _Nx{50};
  int _Ny{50};
  std::string _imageName{"default.bmp"};
  // char *_imageName{"default"};
  std::string PROJECT_PATH{"Pictures"};
  // char *PROJECT_PATH{"Pictures"};
  BMPImage _image{BMPImage(500, 500)};
  // Image _image{BMPImage(500, 500)};

public:
  ImageWriter(const char *imageName, int width, int height, int Ny, int Nx) : _imageWidth(width), _imageHeight(height), _Nx(Nx),
                                                                              _Ny(Ny), _imageName(imageName), _image(BMPImage(width, height))
  {
    std::cout << "ImageWriter CTOR" << std::endl;
  }
  ImageWriter(const ImageWriter &iw) : _imageWidth(iw.getWidth()),
                                       _imageHeight(iw.getHeight()), _Nx(iw.getNx()),
                                       _Ny(iw.getNy()), _imageName(iw.getName()), _image(BMPImage(_imageWidth, _imageHeight)) {}

  std::string getName() const;
  int getWidth() const;
  int getHeight() const;
  int getNx() const;
  void setNx(int);
  int getNy() const;
  void setNy(int);

  void writeToImage(const Image &) const;
  void writePixel(int, int, const Color &, Image &);
  void writePixel(int, int, int, int, int, Image &);
};

std::string ImageWriter::getName() const { return this->_imageName; }
int ImageWriter::getWidth() const { return this->_imageWidth; }
int ImageWriter::getHeight() const { return this->_imageHeight; }

int ImageWriter::getNx() const { return this->_Nx; }
void ImageWriter::setNx(int Nx) { this->_Nx = Nx; }

int ImageWriter::getNy() const { return this->_Ny; }
void ImageWriter::setNy(int Ny) { this->_Ny = Ny; }

void ImageWriter::writeToImage(const Image &im) const
{
  try
  {
    // TODO Write full path to picture
    std::string imageName = this->_imageName;
    std::string suffix = ".bmp";
    std::string fileName = imageName.compare(imageName.size() - suffix.size(), suffix.size(), suffix) == 0 ? imageName : imageName + suffix;
    this->_image.write(fileName);
    im.write(fileName);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    // std::cout << e.what() << '\n';
  }
}

void ImageWriter::writePixel(int xIndex, int yIndex, const Color &color, Image &im)
{
  _image.setRGB(xIndex, yIndex, color);
  im.setRGB(xIndex, yIndex, color);
}

void ImageWriter::writePixel(int xIndex, int yIndex, int r, int g, int b, Image &im)
{
  this->writePixel(xIndex, yIndex, Color(r, g, b), im);
}

#endif // IMAGEWRITER_HPP
