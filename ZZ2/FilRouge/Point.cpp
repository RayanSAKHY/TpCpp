#include "Point.hpp"

Point ORIGINE;

Point::Point(int x, int y) : x(x), y(y)
{
}

void Point::setX(int _x)
{
    x = _x;
}

void Point::setY(int _y)
{
    y = _y;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}