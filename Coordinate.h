//
// Created by Tiki Lobel on 11/20/16.
//

#ifndef EX1_COORDINATE_H
#define EX1_COORDINATE_H

#include <iostream>

using namespace std;
class Coordinate {
public:
     Coordinate(){};
    ~Coordinate(){};
    virtual Coordinate* getCoordinates(){};
    virtual int getX(){};
    virtual int getY(){};
    void print() { subclassPrint();};
    virtual void subclassPrint(){};
    virtual int getNextCoordinate(int place);
    friend std::ostream &operator<<(std::ostream& out, Coordinate&){};
   // virtual void setX(int x) = 0;
   // virtual void setY(int y) = 0;
    //void printIt();
    virtual bool equalTo(Coordinate* c) {};
private:
    int locs[10];
    //int x;
    //int y;

    //virtual void print() = 0;
//    friend bool operator== (Coordinate* const& p1, Coordinate* const& p) {return 0;};


};


#endif //EX1_COORDINATE_H
