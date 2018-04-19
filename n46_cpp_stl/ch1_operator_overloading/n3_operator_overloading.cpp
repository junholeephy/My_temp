#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x=0, int _y=0):x(_x),y(_y) {}
    void Print() const {cout<<x<<","<<y<<endl;}
    
    const Point& operator--()
    {
        x--;
        y--;
        return *this;
    }
    const Point operator--(int)
    {
        Point pt(x,y);
        x--;
        y--;
        return pt;
    }

};


void n3_operator_overloading()
{
    Point tp1, tp2;
    Point p1(12,13); p1.Print();
    tp1 = --p1; tp1.Print(); p1.Print();
    tp2 = p1--; tp2.Print(); p1.Print();
    tp2 = p1--; tp2.Print(); p1.Print();

}


