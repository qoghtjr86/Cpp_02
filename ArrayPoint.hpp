//
//  ArrayPoint.hpp
//  BHS
//
//  Created by 배호석 on 2022/11/03.
//

#ifndef ArrayPoint_hpp
#define ArrayPoint_hpp

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0);
    friend ostream& operator<<(ostream& os, Point& pos);
};

#endif /* ArrayPoint_hpp */
