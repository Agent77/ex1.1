//
// Created by Tiki Lobel on 11/18/16.
//

#ifndef EX1_NODE_H
#define EX1_NODE_H
#include "Node.h"
#include "Point.h"


class Node {

private:
    Point myLocation = Point(0,0);
    Node* prev;
    bool visited = false;
public:
    Node();
    Node(Point p);
    bool isVisited();
    void visit();
    Node* getPrev();
    void setPrev(Node &p);
    Point getLocation();
};

#endif //EX1_NODE_H
