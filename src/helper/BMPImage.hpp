#if !defined(BMPIMAGE_HPP)
#define BMPIMAGE_HPP

#include <fstream>
#include <vector>
#include "Image.hpp"

const int bytesPerPixel = 4; // red, green, blue, alpha
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;

class BMPImage : public Image
{
  private:
    int _height{500};
    int _width{500};
    unsigned char *_image{0};            // All black by default;
    std::vector<unsigned char> _data{0}; // All black by default;

    void generateBitmapImage(int, const char *) const;
    unsigned char *createBitmapFileHeader(int, int) const;
    unsigned char *createBitmapInfoHeader() const;

  public:
    BMPImage(int width, int height) : _width(width), _height(height)
    {
        // _image = new unsigned char[_height][_width][bytesPerPixel];
        _data.resize(width * height * bytesPerPixel);
        std::cout << "BMPImage CTOR" << std::endl;
    }

    void setRGB(int, int, const Color &);
    void write(std::string) const;
};

void BMPImage::generateBitmapImage(int pitch, const char *imageFileName) const
{
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - pitch % 4) % 4; // always 0 because pitch is width * 4
    int height = this->_height;
    int width = this->_width;
    unsigned char *image = this->_image;

    unsigned char *fileHeader = createBitmapFileHeader(pitch, paddingSize); // width * 4, 0
    unsigned char *infoHeader = createBitmapInfoHeader();

    std::ofstream outputFile{imageFileName, std::ios_base::binary};

    // FILE *imageFile = fopen(imageFileName, "wb");

    // fwrite(fileHeader, 1, fileHeaderSize, imageFile);
    // fwrite(infoHeader, 1, infoHeaderSize, imageFile);

    outputFile.write((const char *)fileHeader, fileHeaderSize);
    outputFile.write((const char *)infoHeader, infoHeaderSize);
    outputFile.write((const char *)_data.data(), _data.size());

    // const unsigned char *data = _data.data();

    // // imageFile.write((const char *)_data.data(), _data.size());
    // // of.write((const char *)data.data(), data.size());

    // for (int i = 0; i < height; i++)
    // {
    //     // fwrite(image + (i * pitch), bytesPerPixel, width, imageFile);
    //     fwrite(data + (i * pitch), bytesPerPixel, width, imageFile);
    //     // fwrite(padding, 1, paddingSize, imageFile);
    // }
    // // fwrite(data.data(), data.size(), width, imageFile);

    // fclose(imageFile);
}

unsigned char *BMPImage::createBitmapFileHeader(int pitch, int paddingSize) const
{
    int fileSize = fileHeaderSize + infoHeaderSize + (pitch + paddingSize) * this->_height;

    static unsigned char fileHeader[] = {
        (unsigned char)'B', (unsigned char)'M',                                                                                    /// signature
        (unsigned char)fileSize, (unsigned char)(fileSize >> 8), (unsigned char)(fileSize >> 16), (unsigned char)(fileSize >> 24), /// image file size in bytes
        0, 0, 0, 0,                                                                                                                /// reserved
        (unsigned char)(fileHeaderSize + infoHeaderSize), 0, 0, 0,                                                                 /// start of pixel array
    };

    return fileHeader;
}

unsigned char *BMPImage::createBitmapInfoHeader() const
{
    int height = this->_height;
    int width = this->_width;

    static unsigned char infoHeader[] = {
        (unsigned char)(infoHeaderSize), 0, 0, 0,                                                                            /// header size
        (unsigned char)(width), (unsigned char)(width >> 8), (unsigned char)(width >> 16), (unsigned char)(width >> 24),     /// image width
        (unsigned char)(height), (unsigned char)(height >> 8), (unsigned char)(height >> 16), (unsigned char)(height >> 24), /// image height
        (unsigned char)(1), 0,                                                                                               /// number of color planes
        (unsigned char)(bytesPerPixel * 8), 0,                                                                               /// bits per pixel
        0, 0, 0, 0,                                                                                                          /// compression
        0, 0, 0, 0,                                                                                                          /// image size
        0, 0, 0, 0,                                                                                                          /// horizontal resolution
        0, 0, 0, 0,                                                                                                          /// vertical resolution
        0, 0, 0, 0,                                                                                                          /// colors in color table
        0, 0, 0, 0,                                                                                                          /// important color count
    };

    return infoHeader;
}

void BMPImage::setRGB(int x, int y, const Color &color)
{
    int height = this->_height;
    int width = this->_width;
    if (x < 0 || x > height || y > width || y < 0)
    {
        std::cout << "x = " << x << "y = " << y << std::endl;
        throw std::runtime_error("Pixel out of bond!");
    }
    //     uint32_t channels = bmp_info_header.bit_count / 8;
    //     data[channels * (y * bmp_info_header.width + x) + 0] = B;
    // _image[x][y][0] = (unsigned char)color.getBlue();  // blue
    // _image[x][y][1] = (unsigned char)color.getGreen(); // green
    // _image[x][y][2] = (unsigned char)color.getRed();   // red
    // _image[x][y][3] = (unsigned char)color.getAlpha(); // alpha
    int offset = bytesPerPixel * (y * height + x);
    // std::cout << "OFFSET = " << offset << std::endl;
    _data[offset + 0] = (unsigned char)color.getBlue();  // blue
    _data[offset + 1] = (unsigned char)color.getGreen(); // green
    _data[offset + 2] = (unsigned char)color.getRed();   // red
    _data[offset + 3] = (unsigned char)color.getAlpha(); // alpha
    // _image[offset + 0] = (unsigned char)color.getBlue();  // blue
    // _image[offset + 1] = (unsigned char)color.getGreen(); // green
    // _image[offset + 2] = (unsigned char)color.getRed();   // red
    // _image[offset + 3] = (unsigned char)color.getAlpha(); // alpha
    // std::cout << "setRGB at pixel [" << x << ", " << y << "]" << std::endl;
    // std::cout << "Image {" << std::endl;
    // std::cout << this->_image << std::endl;
    // std::cout << "}" << std::endl;
}

void BMPImage::write(std::string fileName) const
{
    // std::cout << "BMPImage write" << std::endl;
    generateBitmapImage(this->_width * bytesPerPixel, fileName.c_str());
}

// BMPImage::BMPImage(int width, int height)
// {
//     if (width <= 0 || height <= 0)
//     {
//         throw std::runtime_error("The image width and height must be positive numbers.");
//     }

//     bmp_info_header.width = width;
//     bmp_info_header.height = height;

//     bmp_info_header.size = sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);
//     file_header.offset_data = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + sizeof(BMPColorHeader);

//     bmp_info_header.bit_count = 32;
//     bmp_info_header.compression = 3;
//     row_stride = width * 4;
//     data.resize(row_stride * height);
//     file_header.file_size = file_header.offset_data + data.size();
// }

// void BMPImage::setRGB(uint32_t x, uint32_t y, uint8_t B, uint8_t G, uint8_t R, uint8_t A)
// {
//     if (x > (uint32_t)bmp_info_header.width || y > (uint32_t)bmp_info_header.height)
//     {
//         throw std::runtime_error("The region does not fit in the image!");
//     }

//     uint32_t channels = bmp_info_header.bit_count / 8;
//     data[channels * (y * bmp_info_header.width + x) + 0] = B;
//     data[channels * (y * bmp_info_header.width + x) + 1] = G;
//     data[channels * (y * bmp_info_header.width + x) + 2] = R;
//     if (channels == 4)
//     {
//         data[channels * (y * bmp_info_header.width + x) + 3] = A;
//     }
// }

// void BMPImage::setRGB(int x, int y, const Color &color)
// {
//     this->setRGB(x, y, color.getBlue(), color.getGreen(), color.getRed(), color.getAlpha());
// }

// void BMPImage::write(const char *fname) const
// {
//     // std::string bla = "bla";
//     std::ofstream of{fname, std::ios_base::binary};
//     if (of)
//     {
//         if (bmp_info_header.bit_count == 32)
//         {
//             this->write_headers_and_data(of);
//         }
//         else if (bmp_info_header.bit_count == 24)
//         {
//             if (bmp_info_header.width % 4 == 0)
//             {
//                 write_headers_and_data(of);
//             }
//             else
//             {
//                 uint32_t new_stride = make_stride_aligned(4);
//                 std::vector<uint8_t> padding_row(new_stride - row_stride);

//                 write_headers(of);

//                 for (int y = 0; y < bmp_info_header.height; ++y)
//                 {
//                     of.write((const char *)(data.data() + row_stride * y), row_stride);
//                     of.write((const char *)padding_row.data(), padding_row.size());
//                 }
//             }
//         }
//         else
//         {
//             throw std::runtime_error("The program can treat only 24 or 32 bits per pixel BMP files");
//         }
//     }
//     else
//     {
//         throw std::runtime_error("Unable to open the output image file.");
//     }
// }

// void BMPImage::write_headers(std::ofstream &of) const
// {
//     of.write((const char *)&file_header, sizeof(file_header));
//     of.write((const char *)&bmp_info_header, sizeof(bmp_info_header));
//     if (bmp_info_header.bit_count == 32)
//     {
//         of.write((const char *)&bmp_color_header, sizeof(bmp_color_header));
//     }
// }

// void BMPImage::write_headers_and_data(std::ofstream &of) const
// {
//     write_headers(of);
//     of.write((const char *)data.data(), data.size());
// }

// // Add 1 to the row_stride until it is divisible with align_stride
// uint32_t BMPImage::make_stride_aligned(uint32_t align_stride) const
// {
//     uint32_t new_stride = row_stride;
//     while (new_stride % align_stride != 0)
//     {
//         new_stride++;
//     }
//     return new_stride;
// }

#endif // BMPIMAGE_HPP
