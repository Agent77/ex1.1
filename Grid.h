//
// Created by Tiki Lobel on 11/20/16.
//

#ifndef EX1_GRID_H
#define EX1_GRID_H
#include "Node.h"
#include "Point.h"
#include "Graph.h"
#include <string.h>

class Grid : public Graph {
private:
    Node* arrayOfPtrsToNodes[3][3];
    int sizeX;
    int sizeY;
public:
    Grid(int sizeX, int sizeY);
    Node* getLocationOfPrev(Node* n);
    std::vector<Node*> getNeighbors(Node* node);
    void print();
    Node* getNode(Coordinate* p);

};


#endif //EX1_GRID_H
