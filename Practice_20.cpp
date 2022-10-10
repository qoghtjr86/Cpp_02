#include <iostream>
using namespace std;

class Rectangle
{
private:
    int x;
    int y;
public:
    Rectangle(int x, int y)
        : x(x), y(y)
    { }
    void ShowAreaInfo()
    {
        cout<<"면적: "<<x*y<<endl;
    }
};

class Square : public Rectangle
{
private:
    int z;
public:
    Square(int z)
        : Rectangle(z, z)
    { }
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();
    
    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}


