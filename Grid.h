
#ifndef EX1_GRID_H
#define EX1_GRID_H
#include "Node.h"
#include "Point.h"
#include "Graph.h"
#include <string.h>
#include <vector>

class Grid : public Graph {
private:
    Node* arrayOfPtrsToNodes[10][10];
    int sizeX;
    int sizeY;
public:
    Grid(int sizeX, int sizeY);
    Node* getLocationOfPrev(Node* n);
    std::vector<Node*> getNeighbors(Node* node);
    Node* getNode(Coordinate* p);

};


#endif //EX1_GRID_H
