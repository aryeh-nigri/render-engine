#include <stdio.h>
#include <iostream>

// The .bmp file format
// Source: https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html

const int bytesPerPixel = 4; /// red, green, blue, alpha
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;

void generateBitmapImage(unsigned char *image, int height, int width, int pitch, const char *imageFileName);
unsigned char *createBitmapFileHeader(int height, int width, int pitch, int paddingSize);
unsigned char *createBitmapInfoHeader(int height, int width);

void generateBitmapImage(unsigned char *image, int height, int width, int pitch, const char *imageFileName)
{
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - pitch % 4) % 4;

    unsigned char *fileHeader = createBitmapFileHeader(height, width, pitch, paddingSize);
    unsigned char *infoHeader = createBitmapInfoHeader(height, width);

    FILE *imageFile = fopen(imageFileName, "wb");

    fwrite(fileHeader, 1, fileHeaderSize, imageFile);
    fwrite(infoHeader, 1, infoHeaderSize, imageFile);

    int i;
    for (i = 0; i < height; i++)
    {
        fwrite(image + (i * pitch /*width*bytesPerPixel*/), bytesPerPixel, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
    //free(fileHeader);
    //free(infoHeader);
}

unsigned char *createBitmapFileHeader(int height, int width, int pitch, int paddingSize)
{
    int fileSize = fileHeaderSize + infoHeaderSize + (pitch + paddingSize) * height;

    static unsigned char fileHeader[] = {
        (unsigned char)'B', (unsigned char)'M',                                                                                    /// signature
        (unsigned char)fileSize, (unsigned char)(fileSize >> 8), (unsigned char)(fileSize >> 16), (unsigned char)(fileSize >> 24), /// image file size in bytes
        0, 0, 0, 0,                                                                                                                /// reserved
        (unsigned char)(fileHeaderSize + infoHeaderSize), 0, 0, 0,                                                                 /// start of pixel array
    };

    return fileHeader;
}

unsigned char *createBitmapInfoHeader(int height, int width)
{
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

int main(int argc, char const *argv[])
{

    const int height = 800;
    const int width = 600;
    unsigned char image[height][width][bytesPerPixel] = {0}; // Black by default
    char *imageFileName = "gridImageWriterTest.bmp";

    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i % 50 == 0 || j % 50 == 0)
            {
                image[i][j][2] = (unsigned char)255; ///red
                image[i][j][1] = (unsigned char)255; ///green
                image[i][j][0] = (unsigned char)255; ///blue
                // instance.writePixel(i, j, Color::WHITE);
            }
        }
    }

    generateBitmapImage((unsigned char *)image, height, width, width * bytesPerPixel, imageFileName);
    printf("Image generated!!");

    return 0;
}
