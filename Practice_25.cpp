#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    bool operator==(const Point &pos2)
    {
        if(this->xpos==pos2.xpos && this->ypos==pos2.ypos)
            return true;
        else
            return false;
    }
    bool operator!=(const Point &pos2)
    {
        if((this->operator==(pos2))==true)
           return false;
        else
           return true;
    }
};

int main(void)
{
    Point pos1=Point(14, 7);
    Point pos2=Point(14, 7);
    Point pos3=Point(4, 6);
    
    bool result1=(pos1==pos2);
    bool result2=(pos2==pos3);
    bool result3=(pos1!=pos3);
    cout<<result1<<endl;
    cout<<result2<<endl;
    cout<<result3<<endl;
    return 0;
}
