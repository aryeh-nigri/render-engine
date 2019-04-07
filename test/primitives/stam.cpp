#include "../../src/primitives/Vector.h"

int main(int argc, char const *argv[])
{

    Point3D p;
    Vector v1, v2(p), v3;

    std::cout << &v1 << std::endl;
    std::cout << &v2 << std::endl;
    std::cout << &v3 << std::endl;

    Vector v4 = v1;
    std::cout << &v4 << "   -   " << &v1 << std::endl;

    std::cout << &p << std::endl;
    Point3D p2 = v2.getHead();
    std::cout << &p2 << std::endl;

    return 0;
}
