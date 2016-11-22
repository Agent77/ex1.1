//
// Created by Tiki Lobel on 11/20/16.
//

#include "Grid.h"

Grid::Grid(int xSize, int ySize) {
    sizeX = xSize;
    sizeY = ySize;
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            Point* p;
            p = new Point(i, j);
            Node* n;
            n = new Node(p);//Creates a point
            arrayOfPtrsToNodes[i][j] = n;
        }
    }
}

Node* Grid::getLocationOfPrev(Node* n) {
    Node* prevNode = n->getPrev();
    return prevNode;
}

void Grid::print(){
    std::cout<<"sup? i'm grid";
}

Node* Grid::getNeighbors(Node n) {
    Node* neighbors;
    Coordinate* p = (n.getLocation());
    Point point(p);
    //Does same exact thing, but much more generic!!!!!!!
    Coordinate* code = p->getCoordinates();
    Point point2(code);
    int count = -1;
    int x = (point.getX());
    int y = (point.getY());
    if ((x - 1) >= 0) {
        count++;
        neighbors[count] = *arrayOfPtrsToNodes[(point.getX()) - 1][(point).getY()];
        neighbors->visit();
        neighbors->setPrev(&n);
    }
    if (y + 1 < sizeY) {
        count++;
        neighbors[count] = *arrayOfPtrsToNodes[(point).getX()][(point).getY() + 1];
        neighbors->visit();
        neighbors->setPrev(&n);
    }
    if((x + 1) < sizeX) {
        count++;
        neighbors[count] = *arrayOfPtrsToNodes[(point).getX() + 1][(point).getY()];
        neighbors->visit();
        neighbors->setPrev(&n);
    }
    if((y - 1) >= 0) {
        count++;
        neighbors[count] = *arrayOfPtrsToNodes[point.getX()][point.getY() - 1];
        neighbors->visit();
        neighbors->setPrev(&n);
    }
    return neighbors;
}

Node* Grid::getNode(Coordinate* p){
    Node* node = (arrayOfPtrsToNodes[p->getNextCoordinate(0)][p->getNextCoordinate(1)]);
    return node;
}