#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    
    int GetXpos() {return xpos;}
    int GetYpos() {return ypos;}
    void SetXpos(int num) {xpos=num;}
    void SetYpos(int num) {ypos=num;}
    
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    
    template <class T>
    void SwapData(T num1, T num2)
    {
        SetXpos(num2);
        SetYpos(num1);
    }

};


int main(void)
{
    Point pos(5, 4);
    pos.SwapData<int>(pos.GetXpos(), pos.GetYpos());
    pos.ShowPosition();
    return 0;
}
