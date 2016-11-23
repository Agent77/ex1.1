
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
    virtual int getNextCoordinate(int place);
    friend std::ostream &operator<<(std::ostream& out, Coordinate&){};
    virtual bool equalTo(Coordinate* c) {};
private:
    int locs[10];
   };


#endif //EX1_COORDINATE_H
