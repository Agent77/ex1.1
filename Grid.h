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
    Node* grid[10][10];
public:
    Grid(int sizeX, int sizeY);
    Node* getLocationOfPrev(Node* n);
    Node* getNeighbors(Node* node);
    void print();

};


#endif //EX1_GRID_H
