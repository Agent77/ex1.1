

#ifndef EX1_POINT_H
#define EX1_POINT_H
#include <iostream>
#include "Coordinate.h"

class Point: public Coordinate {
private:
    int locs[2];
public:
    Point();
    ~Point();
    Point(int xAxis, int yAxis);
    friend std::ostream &operator<<(std::ostream& out, Point&);
    bool equalTo(Coordinate* c);
    friend bool operator== (Point const& p, Point const& p2);
    int getX();
    Coordinate* getCoordinates();
    Point(Coordinate* cor);
    int getY();
    int getNextCoordinate(int place);
};
#endif //EXONE_POINT_H