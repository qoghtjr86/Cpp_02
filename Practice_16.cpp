#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos=x;
        ypos=y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Radius
{
private:
    int radius;
public:
    void Init(int r)
    {
        radius=r;
    }
    void ShowRadiusInfo() const {cout<<"radius: "<<radius<<endl;}
};

class Circle
{
private:
    Point pos;
    Radius rad;
public:
    void Init(int x, int y, int r)
    {
        pos.Init(x, y);
        rad.Init(r);
    }
    void ShowCircleInfo(){
        rad.ShowRadiusInfo();
        pos.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle Inner;
    Circle Outter;
public:
    void Init(int Ix, int Iy, int Ir, int Ox, int Oy, int Or)
    {
        Inner.Init(Ix, Iy, Ir);
        Outter.Init(Ox, Oy, Or);
    }
    void ShowRingInfo()
    {
        cout<<"Inner Circle Info..."<<endl;
        Inner.ShowCircleInfo();
        cout<<"Outter Circle Info..."<<endl;
        Outter.ShowCircleInfo();
    }
    
};

int main()
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}
