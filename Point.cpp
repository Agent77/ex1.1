

#include "Point.h"

using namespace std;
Point::Point() {

}
Point::Point(int xAxis, int yAxis) {
    locs[0] = xAxis;
    locs[1] = yAxis;
}

ostream& operator<<(ostream& output, Point& p) {
    output << "(" << p.getX() << "," << p.getY() << ")";
    return output;
}

bool Point::equalTo(Coordinate *c) {
    Point point(c);
    bool equal =  (locs[0] == (point.getX()) && (locs[1] == (point.getY())));
    return equal;
}
int Point::getY() {
    return locs[1];
}

Point::Point(Coordinate *cor) { //TODO changes made
    int size = sizeof(locs)/4;
    for(int i = 0; i< size; i++) {
        locs[i] = cor->getNextCoordinate(i);
    }
}
int Point::getNextCoordinate(int place) {
    return locs[place];
}

int Point::getX() {
    return locs[0];
}

Coordinate* Point::getCoordinates() {
    Point* p = new Point(locs[0], locs[1]);
    return p;

}
Point::~Point() {

}