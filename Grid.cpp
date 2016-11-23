#include "Grid.h"

Grid::Grid(int xSize, int ySize) {
    sizeX = xSize;
    sizeY = ySize;
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            Point p = Point(i, j);
            Node* n;
            n = new Node(&p);//Creates a point
            arrayOfPtrsToNodes[i][j] = n;
        }
    }
}

Node* Grid::getLocationOfPrev(Node* n) {
    Node* prevNode = new Node(*(n->getPrev()));
    return prevNode;
}

std::vector<Node*> Grid::getNeighbors(Node* n) {
    std::vector<Node*> neighbors;
    Coordinate* p = (*(n)).getLocation();
    Point point(p);
    int x = (point.getX());
    int y = (point.getY());
    if ((x - 1) >= 0) {
         Node* node = (arrayOfPtrsToNodes[(point.getX()) - 1][(point).getY()]);
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    if (y + 1 < sizeY) {

        Node* node = (arrayOfPtrsToNodes[(point).getX()][(point).getY() + 1]);
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    if((x + 1) < sizeX) {
        Node* node = arrayOfPtrsToNodes[(point).getX() + 1][(point).getY()];
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    if((y - 1) >= 0) {

        Node* node = arrayOfPtrsToNodes[point.getX()][point.getY() - 1];
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    return neighbors;
}

Node* Grid::getNode(Coordinate* p){
    Node* node = (arrayOfPtrsToNodes[p->getNextCoordinate(0)][p->getNextCoordinate(1)]);
    return node;
}