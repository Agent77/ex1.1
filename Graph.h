//
// Created by Tiki Lobel on 11/20/16.
//

#ifndef EX1_GRAPH_H
#define EX1_GRAPH_H

#include "Node.h"

class Graph {
public:
    Graph(){};
    virtual Node* getLocationOfPrev(Node* n) {};
    virtual Node* getNeighbors(Node n)=0;
    virtual void print()=0;
    virtual Node* getNode(Coordinate* p){};
};


#endif //EX1_GRAPH_H
