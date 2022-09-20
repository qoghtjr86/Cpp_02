#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Point.hpp"

class Rectangle
{
private:
    Point upLeft;
    Point lowRight;
    
public:
    bool InitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const;
};
#endif
