//
// Created by Tiki Lobel on 11/20/16.
//

#include "Grid.h"

Grid::Grid(int sizeX, int sizeY) {
    for(int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            Point p = Point(i,j);
            Node* n;
            Node node = Node(p);
            n = &(node);
            grid[i][j] = n;
        }
    }
}

Node* Grid::getLocationOfPrev(Node* n) {
    Coordinate* c = n->getPrev()->getLocation();
    Node* node = grid[((*(c)).getX())][(*(c)).getY()];
    return node;
}

Node* Grid::getNeighbors(Node* n) {
    Node* neighbors;
    Coordinate* c = n->getLocation();
    if ((*(c)).getX()- 1 >= 0) {
        neighbors = (grid[((*(c)).getX()) - 1][(*(c)).getY()]);
    }
    if ((((*(c)).getY()) + 1) < 10) {
        neighbors++;
        neighbors = (grid[(*(c)).getX()][((*(c)).getY()) + 1]);
    }
    if((((*(c)).getX()) + 1) < 10) {
        neighbors++;
        neighbors = (grid[((*(c)).getX()) + 1][((*(c)).getY())]);
    }
    if(((*(c)).getY()) - 1 >= 0) {
        neighbors++;
        neighbors = (grid[((*(c)).getX())][((*(c)).getY()) - 1]);
    }
    return neighbors;
}
