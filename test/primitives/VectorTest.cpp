#include "../../src/primitives/Vector.h"

void fail(const char *);
void assertEquals(const Vector &, const Vector &);
void assertEquals(double, double);
void testAdd();
void testSubtract();
void testDotProduct();
void testCrossProduct();
void testLength();
void testScaling();
void testNormalize();
void testDistance();

int main(int argc, char const *argv[])
{
    testAdd();
    testSubtract();
    testDotProduct();
    testCrossProduct();
    testLength();
    testScaling();
    testNormalize();
    testDistance();

    return 0;
}

void fail(const char *msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

void assertEquals(const Vector &v1, const Vector &v2)
{
    if (v1 == v2)
    {
        std::cout << v1 << " = " << v2 << std::endl;
    }
    else
    {
        const char *errorMsg = "v1 != v2";
        fail(errorMsg);
    }
}

void assertEquals(double d1, double d2)
{
    if (d1 == d2)
    {
        std::cout << d1 << " = " << d2 << std::endl;
    }
    else
    {
        const char *errorMsg = "d1 != d2";
        fail(errorMsg);
    }
}

void testAdd()
{
    std::cout << "ADD" << std::endl;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Coordinate r1 = Coordinate(4.0);
    Coordinate r2 = Coordinate(4.0);
    Coordinate r3 = Coordinate(4.0);
    Vector vec = Vector(Point3D(x, y, z));          //   (1, 2, 3)
    Vector instance = Vector(Point3D(z, y, x));     //   (3, 2, 1)
    Vector expResult = Vector(Point3D(r1, r2, r3)); //   (4, 4, 4)
    Vector result = instance + vec;                 //instance.add(vec);
    assertEquals(expResult, result);
}

void testSubtract()
{
    std::cout << "SUBTRACT" << std::endl;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Coordinate r1 = Coordinate(2.0);
    Coordinate r2 = Coordinate(0.0);
    Coordinate r3 = Coordinate(-2.0);
    Vector vec = Vector(Point3D(x, y, z));          //   (1, 2, 3)
    Vector instance = Vector(Point3D(z, y, x));     //   (3, 2, 1)
    Vector expResult = Vector(Point3D(r1, r2, r3)); //   (2, 0, -2)
    Vector result = instance - vec;                 //instance.subtract(vec);
    assertEquals(expResult, result);
}

void testDotProduct()
{
    std::cout << "DOT PRODUCT" << std::endl;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Vector vec = Vector(Point3D(x, y, z));      //   (1, 2, 3)
    Vector instance = Vector(Point3D(z, y, x)); //   (3, 2, 1)
    double expResult = 10.0;                    //   3*1 + 2*2 + 1*3 = 10
    double result = instance * vec;             //instance.dotProduct(vec);
    assertEquals(expResult, result);
}

void testCrossProduct()
{
    std::cout << "CROSS PRODUCT" << std::endl;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Coordinate r1 = Coordinate(4.0);
    Coordinate r2 = Coordinate(-8.0);
    Coordinate r3 = Coordinate(4.0);
    Vector vec = Vector(Point3D(x, y, z));          //   (1, 2, 3)
    Vector instance = Vector(Point3D(z, y, x));     //   (3, 2, 1)
    Vector expResult = Vector(Point3D(r1, r2, r3)); //   (4, -8, 4)
    Vector result = instance.crossProduct(vec);
    assertEquals(expResult, result);
}

void testLength()
{
    std::cout << "LENGTH" << std::endl;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Vector instance = Vector(Point3D(x, y, z)); //   (1, 2, 3)
    double expResult = sqrt(14.0);
    double result = instance.length();
    assertEquals(expResult, result);
}

void testScaling()
{
    std::cout << "SCALING" << std::endl;
    double scalar = 2.5;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Coordinate r1 = Coordinate(2.5);
    Coordinate r2 = Coordinate(5.0);
    Coordinate r3 = Coordinate(7.5);
    Vector instance = Vector(Point3D(x, y, z));     //   (1, 2, 3)
    Vector expResult = Vector(Point3D(r1, r2, r3)); //   (2.5, 5.0, 7.5)
    Vector result = instance * scalar;              //instance.scaling(scalar);
    assertEquals(expResult, result);
}

void testNormalize()
{
    std::cout << "NORMALIZE" << std::endl;
    Coordinate x = Coordinate(1.0);
    Coordinate y = Coordinate(2.0);
    Coordinate z = Coordinate(3.0);
    Vector instance = Vector(Point3D(x, y, z)); //   (1, 2, 3)
    Vector vec = instance * 3.0;                //instance.scaling(3.0);

    instance.normalize();
    vec.normalize();

    assertEquals(instance, vec);

    Vector v = Vector(3.5, -5.0, 10.0);
    v.normalize(); //   (0.298752719843424, -0.42678959977632, 0.85357919955264)
    assertEquals(1, v.length());
}

void testDistance()
{
    std::cout << "DISTANCE" << std::endl;
    Point3D p1 = Point3D();
    Point3D p2 = Point3D(1.0, 2.0, 2.0);
    Point3D p3 = Point3D(2.0, 4.0, 4.0);

    double d1 = p2.distance(p1); //   should be 3.0
    double d2 = p3.distance(p3); //   should be 0.0
    double d3 = p3.distance(p2); //   should be 3.0
    double d4 = p2.distance(p3); //   should be same as d3

    if (d1 != 3.0)
    {
        fail("d1 failed!");
    }
    assertEquals(d1, 3.0);
    if (d2 != 0.0)
    {
        fail("d2 failed!");
    }
    assertEquals(d2, 0.0);
    if (d3 != 3.0)
    {
        fail("d3 failed!");
    }
    assertEquals(d3, 3.0);
    if (d4 != d3)
    {
        fail("d4 failed");
    }
    assertEquals(d4, d3);
}