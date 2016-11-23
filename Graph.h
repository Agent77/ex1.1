//
// Created by Tiki Lobel on 11/20/16.
//

#ifndef EX1_GRAPH_H
#define EX1_GRAPH_H

#include <vector>
#include "Node.h"

class Graph {
public:
    Graph(){};
    virtual Node* getLocationOfPrev(Node* n) {};
    virtual std::vector<Node*> getNeighbors(Node* n)=0;
    virtual Node* getNode(Coordinate* p){};
};


#endif //EX1_GRAPH_H
