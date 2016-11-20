//
// Created by Tiki Lobel on 11/20/16.
//

#ifndef EX1_BFSGENERIC_H
#define EX1_BFSGENERIC_H
#include "Point.h"

class BFSgeneric {
private:
    queue<Node*> myQueue;
    Node source;
    Node destination;
public:
    BFSgeneric(int sizeX, int sizeY, Point source, Point destination);
    void visitNeighbors(Node &n);
    void getPath();
    void PrintPath(Node s, Node d);
};


#endif //EX1_BFSGENERIC_H



