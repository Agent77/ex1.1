
#ifndef EX1_COORDINATE_H
#define EX1_COORDINATE_H

#include <iostream>
/*
 * Abstract class to represent an objects location,
 * based on any number of coordinates given, using an
 * array of locations (x,y,z,etc...). This allows
 * us to handle any dimension wanted by the user.
 */
using namespace std;
class Coordinate {
public:
     Coordinate(){};
    ~Coordinate(){};
    virtual Coordinate* getCoordinates(){};
    virtual int getX(){};
    virtual int getY(){};
    virtual int getNextCoordinate(int place);
    friend std::ostream &operator<<(std::ostream& out, Coordinate&){};
    virtual bool equalTo(Coordinate* c) {};
private:
    int locs[10];
   };


#endif //EX1_COORDINATE_H
