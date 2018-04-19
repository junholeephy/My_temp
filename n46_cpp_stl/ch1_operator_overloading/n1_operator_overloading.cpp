#include <iostream>
using namespace std;
class Point
{
    int x;
    int y;

public:
    Point(int _x=0, int _y=0):x(_x),y(_y)  {}
    void Print() const {cout<<x<<","<<y<<endl;}
    const Point operator+ (const Point &arg) const
    {
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;
        return pt;
    }
};
void n1_operator_overloading()
{
    Point p1(2,3);
    Point p2(7,10);
    Point test_p1, test_p2;
    test_p1 = p1+p2;
    test_p1.Print();

    test_p2= p1.operator+(p2);
    test_p2.Print();
}

