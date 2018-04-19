// two ++ operator, locates front and behind of 'x' for each.

#include <iostream>
using namespace std;
class Point
{
    int x; 
    int y;
public:
    Point(int _x=0, int _y=0):x(_x),y(_y) {}
    void Print() const {cout<<x<<","<<y<<endl;}    
    const Point& operator++()
    {
        x++;
        y++;
        return *this;
    }
    const Point operator++(int)
    {
        Point pt(x,y);
        x++;
        y++;
        return pt;
    }
};

int n2_operator_overloading()
{
    Point tp1, tp2;
    Point p1(2,3); p1.Print();
    tp1 = ++p1; p1.Print(); tp1.Print();    
    tp2 = p1++; p1.Print(); tp2.Print();

    return 0;
}




