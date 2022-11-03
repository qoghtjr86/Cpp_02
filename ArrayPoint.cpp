#include <iostream>
#include "ArrayPoint.hpp"
using namespace std;

Point::Point(int x, int y) : xpos(x), ypos(y) { }

ostream& operator<<(ostream& os, Point& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
