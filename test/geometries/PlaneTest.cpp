#include "../../src/geometries/Plane.h"
#include "../../src/elements/Camera.h"

void printList(std::list<Point3D> list)
{
    std::cout << "List size = " << list.size() << std::endl;
    std::list<Point3D>::iterator it;
    for (it = list.begin(); it != list.end(); ++it)
        std::cout << '\t' << *it;
    std::cout << '\n';
}

void testFindIntersections()
{
    std::cout << "findIntersections" << std::endl;

    Plane p1 = Plane(Vector(0, 0, -1), Point3D(0, 0, -3));
    Plane p2 = Plane(Vector(0, 0.25, -1.0), Point3D(0, 0, -3));

    int count1 = 0;
    int count2 = 0;
    int expCount1 = 9;
    int expCount2 = 9;

    Camera cam = Camera(Point3D(), Vector(0, 1, 0), Vector(0, 0, -1));

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            Ray r = cam.constructRayThroughPixel(3, 3, i, j, 1.0, 9.0, 9.0);
            std::list<Point3D> exp1 = p1.findIntersections(r);
            std::list<Point3D> exp2 = p2.findIntersections(r);
            std::cout << "point1 at (" << i << ", " << j << "): ";
            printList(exp1);
            count1 += exp1.size();
            std::cout << "point2 at (" << i << ", " << j << "): ";
            printList(exp2);
            count2 += exp2.size();
        } //inner for
    }     //outer for

    if (count1 != expCount1)
    {
        std::cout << "First test failed!" << std::endl;
        std::cout << "count1 = " << count1 << std::endl;
        return;
    }
    else
    {
        std::cout << "First test succeeded" << std::endl;
    }

    if (count2 != expCount2)
    {
        std::cout << "Second test failed!" << std::endl;
        std::cout << "count2 = " << count2 << std::endl;
        return;
    }
    else
    {
        std::cout << "Second test succeeded" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    testFindIntersections();
    return 0;
}
