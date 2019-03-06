#include "../../src/primitives/Point2D.h"

int main(int argc, char const *argv[])
{
    std::cout << "Test start" << std::endl;

    Point2D a, b(3, 7), c(Coordinate(4), Coordinate(9));
    
    Point2D d(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    b == d? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;

    std::cout << &b << std::endl;
    std::cout << &d << std::endl;

    b.setX(Coordinate(11));
    
    std::cout << b << std::endl;
    std::cout << d << std::endl;

    std::cin.ignore();
    std::cin.get();    

    return 0;
}