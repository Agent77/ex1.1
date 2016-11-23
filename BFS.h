//
// Created by Tiki Lobel on 11/17/16.
//

#ifndef EX1_BFS_H
#define EX1_BFS_H
#include "Node.h"
#include <queue>
#include "Graph.h"
#include "Grid.h"


using namespace std;
class BFS {
private:
    std::queue<Node*> myDeque;
    int xsize;
    int ysize;
    Node* source;
    Graph* graph;
    Node* destination = source;
public:
    BFS(Graph* g, int x, int y, Coordinate* source, Coordinate* destination);
    void getPath();
    void PrintPath(Node* s, Node* d);
    void visitNeighbors(Node* n);
};

#endif //EXONE_BFS_H
