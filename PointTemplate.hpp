#ifndef PointTemplate_hpp
#define PointTemplate_hpp

template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x=0, T y=0);
    void ShowPosition() const;
};

#endif /* PointTemplate_hpp */
