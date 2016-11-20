

#ifndef EX1_POINT_H
#define EX1_POINT_H
#include <iostream>
#include "Coordinate.h"

class Point: public Coordinate {

private:
    int x, y;
public:
    Point();
    Point(int xAxis, int yAxis);
    friend std::ostream &operator<<(std::ostream& out, Point&);
    bool equalTo(Coordinate* c);
    //friend bool operator== (Coordinate* const& p1, Coordinate* const& p);
    int getX() const;
    int getY() const;
};
#endif //EXONE_POINT_H