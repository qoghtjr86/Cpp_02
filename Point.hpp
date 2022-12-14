#ifndef Point_hpp
#define Point_hpp

class Point
{
private:
    int x;
    int y;
    
public:
    Point(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif
