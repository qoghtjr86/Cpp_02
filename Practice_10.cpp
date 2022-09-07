#include <iostream>
using namespace std;

struct Point
{
    int xpos;
    int ypos;
};

Point& PntAdder(Point &p1, Point &p2)
{
    Point *tmp=new Point;
    
    tmp->xpos=p1.xpos+p2.xpos;
    tmp->ypos=p1.ypos+p2.ypos;
    
    return *tmp;
}

int main()
{
    Point *p1=new Point;
    Point *p2=new Point;
    
    p1->xpos=4;p1->ypos=6;
    p2->xpos=7;p2->ypos=14;
    
    Point &p3=PntAdder(*p1, *p2);
    
    cout<<"x: "<<p3.xpos<<endl;
    cout<<"y: "<<p3.ypos<<endl;

    delete p1;
    delete p2;
    delete &p3;
}
