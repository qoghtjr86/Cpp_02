#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point& operator+=(const Point &pos2)
    {
        this->xpos=this->xpos+pos2.xpos;
        this->ypos=this->ypos+pos2.ypos;
        return *this;
    }
    Point& operator-=(const Point &pos2)
    {
        this->xpos=this->xpos-pos2.xpos;
        this->ypos=this->ypos-pos2.ypos;
        return *this;
    }
};

int main(void)
{
    Point pos1(14, 7);
    Point pos2(3, 9);
    (pos1+=pos2).ShowPosition();
    (pos1-=pos2).ShowPosition();
    return 0;
}
