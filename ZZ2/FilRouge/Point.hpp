#ifndef FILROUGE_POINT_HPP
#define FILROUGE_POINT_HPP


class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y);
    Point();
    int getX() const;
    int getY() const;
    void setX(int _x);
    void setY(int _y);
};

extern Point ORIGINE;

#endif //FILROUGE_POINT_HPP