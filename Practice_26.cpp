#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point& operator-()
    {
        this->xpos=-this->xpos;
        this->ypos=-this->ypos;
        return *this;
    }
    friend Point& operator~(Point &pos2);
};

Point& operator~(Point &pos2)
{
    int tmp=0;
    tmp=pos2.xpos;
    pos2.xpos=pos2.ypos;
    pos2.ypos=tmp;
    return pos2;
}

int main(void)
{
    Point pos1(14, 7);
    Point pos2(4, 6);
    Point pos3= -(pos2);
    Point pos4= ~pos2;
    
    pos3.ShowPosition();
    pos4.ShowPosition();
    return 0;
}
