#ifndef Point_hpp
#define Point_hpp

class Point
{
private:
    int x;
    int y;
    
public:
    bool initMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif
