//
// Created by Tiki Lobel on 11/17/16.
//
#include <iostream>
#include "Point.h"

using namespace std;
Point::Point() {

}
Point::Point(int xAxis, int yAxis) {
    //TODO Can be for all points
    locs[0] = xAxis;
    locs[1] = yAxis;
    //x = xAxis;
    //y = yAxis;
}

void Point::print(){
    std::cout<<"i'm point!";
}

ostream& operator<<(ostream& output, Point& p) {
    output << "(" << p.getX() << "," << p.getY() << ")";
    return output;
}
//bool operator== (Coordinate* const& p1, Coordinate* const& p2) {
//    return ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY()));
//}
bool Point::equalTo(Coordinate *c) {
    Point* p=(Point *) c;
        return (x == ((*p).getX()) && (y == ((*p).getY())));
}
int Point::getY() {
    return locs[1];
}

Point::Point(Coordinate *cor) { //TODO changes made
    int size = sizeof(locs)/4;
    for(int i = 0; i< size; i++) {
        locs[i] = cor->getNextCoordinate(i);
    }
    //this->x = cor->getX();
    //this->y = cor->getY();
}
int Point::getNextCoordinate(int place) {
    return locs[place];
}

int Point::getX() {
    return locs[0];
}

void Point::subclassPrint() {
    std::cout<<"IM A POINT!"<<std::endl;
}

Coordinate* Point::getCoordinates() {
    Point* p = new Point(locs[0], locs[1]);
    return p;

}
Point::~Point() {

}