#include "../../src/primitives/Coordinate.h"

int main(int argc, char const *argv[])
{
    std::cout << "Test start" << std::endl;

    Coordinate a, b, c, d;
    a.setCoordinate(5);
    b.setCoordinate(7);

    c = a + b;
    a = a - b;


    d.setCoordinate(12);

    if(c == d){
        std::cout << "operator+ passed" << std::endl;
    }else
    {
        std::cout << "failed" << std::endl;
    }

    std::cout << a << std::endl;

    std::cin.ignore();
    std::cin.get();    

    return 0;
}