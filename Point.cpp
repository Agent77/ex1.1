//
// Created by Tiki Lobel on 11/17/16.
//
#include <iostream>
#include "Point.h"

using namespace std;
Point::Point() {

}
Point::Point(int xAxis, int yAxis) {
    x = xAxis;
    y = yAxis;
}

ostream& operator<<(ostream& output, Point& p) {
    output << "(" << p.getX() << "," << p.getY() << ")";
    return output;
}
bool operator== (Point const& p1, Point const& p2) {
    return ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY()));

}

int Point::getY() const {
    return y;
}

int Point::getX() const {
    return x;
}
