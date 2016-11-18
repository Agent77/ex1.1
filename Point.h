

#ifndef EX1_POINT_H
#define EX1_POINT_H
#include <iostream>

class Point {

private:
    int x, y;
public:
    Point();
    Point(int xAxis, int yAxis);
    friend std::ostream &operator<<(std::ostream& out, Point&);
    friend bool operator== (Point const& p1, Point const& p);
    int getX() const;
    int getY() const ;
};
#endif //EXONE_POINT_H