//
// Created by Tiki Lobel on 11/18/16.
//

#ifndef EX1_NODE_H
#define EX1_NODE_H
#include "Node.h"
#include "Point.h"
#include "Coordinate.h"


class Node {
private:
    Coordinate* myLocation;
    Node* prev;
    bool visited;
public:
    Node* neighbors;
    Node();
    Node(Coordinate* c);
    bool isVisited();
    void visit();
    Node* getPrev();
    void setPrev(Node* n);
    Coordinate* getLocation();
};

#endif //EX1_NODE_H
