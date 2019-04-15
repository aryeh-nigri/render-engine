#include "../../src/renderer/ImageWriter.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

/**
* Test of writeToImage method, of class ImageWriter.
*/
void testWriteToImage()
{
    std::cout << "testWriteToImage" << std::endl;

    ImageWriter instance = ImageWriter("gridImageWriterTest3", 600, 400, 20, 40);
    for (int i = 1; i < instance.getHeight(); i++)
    {
        for (int j = 1; j < instance.getWidth(); j++)
        {
            if (i % instance.getNx() == 0 || j % instance.getNy() == 0)
            {
                // std::cout << "i = " << i << ", j = " << j << std::endl;
                instance.writePixel(i, j, Color::WHITE);
            }
        }
    }
    instance.writeToImage();
}

/**
     * Test of writeToImage method, of class ImageWriter.
     * This text should create a nice visual image, of colored squares.
     */
void testWriteToImage2()
{
    std::cout << "testWriteToImage2" << std::endl;
    /* initialize random seed: */
    srand(time(NULL));
    ImageWriter instance = ImageWriter("niceImageTest", 500, 500, 1, 1);

    int height = instance.getHeight();
    int width = instance.getWidth();

    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            if (i % 25 == 0 || j % 25 == 0 || i == j || i == (width - j))
                ;
            // imageWriter.writePixel(i, j, 0, 0, 0); // Black
            else if (i >= 200 && i <= 300 && j >= 200 && j <= 300)
                instance.writePixel(i, j, 255, 0, 0); // Red
            else if (i >= 150 && i <= 350 && j >= 150 && j <= 350)
                instance.writePixel(i, j, 0, 255, 0); // Green
            else if (i >= 100 && i <= 400 && j >= 100 && j <= 400)
                instance.writePixel(i, j, 0, 0, 255); // Blue
            else if (i >= 50 && i <= 450 && j >= 50 && j <= 450)
                instance.writePixel(i, j, 255, 255, 0); // Yellow
            else
                instance.writePixel(i, j, rand() % 256, rand() % 256, rand() % 256); // Random
        }
    }
    instance.writeToImage();
}

int main(int argc, char const *argv[])
{
    // testWriteToImage();
    testWriteToImage2();
    return 0;
}
