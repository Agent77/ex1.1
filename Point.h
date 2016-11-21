

#ifndef EX1_POINT_H
#define EX1_POINT_H
#include <iostream>
#include "Coordinate.h"

class Point: public Coordinate {
private:
    int x, y;
    int locs[2];
public:
    Point();
    Point(int xAxis, int yAxis);
    friend std::ostream &operator<<(std::ostream& out, Point&);
    bool equalTo(Coordinate* c);
    friend bool operator== (Point const& p, Point const& p2);
    int getX();
    void subclassPrint();
    Coordinate* getCoordinates();
    Point(Coordinate* cor);
    int getY();
    void print();
    int getNextCoordinate(int place);
};
#endif //EXONE_POINT_H