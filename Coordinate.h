//
// Created by Tiki Lobel on 11/20/16.
//

#ifndef EX1_COORDINATE_H
#define EX1_COORDINATE_H


class Coordinate {
public:
     Coordinate();
    ~Coordinate();
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual bool equalTo(Coordinate* c) = 0;
//    friend bool operator== (Coordinate* const& p1, Coordinate* const& p) {return 0;};


};


#endif //EX1_COORDINATE_H
