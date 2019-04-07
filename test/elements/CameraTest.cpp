#include "../../src/elements/Camera.h"

void testConstructRayThroughPixel()
{
    std::cout << "testConstructRayThroughPixel" << std::endl;

    Camera instance = Camera(Point3D(), Vector(0, 1, 0), Vector(0, 0, -1));

    int count = 0;
    int expected = 9;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            Ray ray = instance.constructRayThroughPixel(3, 3, i, j, 1.0, 9.0, 9.0);

            double x = ray.getPOO().getX().getCoordinate();
            double y = ray.getPOO().getY().getCoordinate();
            double z = ray.getPOO().getZ().getCoordinate();

            if (z == -1.0)
            {
                if (x == 3.0 || x == 0.0 || x == -3.0)
                {
                    if (y == 3.0 || y == 0.0 || y == -3.0)
                    {
                        std::cout << "Ray at accepted point: " << ray.getPOO() << std::endl;
                        count++;
                    }
                    else
                    {
                        std::cout << "Y out of range: " << ray.getPOO() << std::endl;
                        return;
                    }
                }
                else
                {
                    std::cout << "X out of range: " << ray.getPOO() << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Z out of range: " << ray.getPOO() << std::endl;
                return;
            }

        } //inner for
    }     //outer for

    if (count == expected)
    {
        std::cout << "Test successfully passed" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    testConstructRayThroughPixel();
    return 0;
}
