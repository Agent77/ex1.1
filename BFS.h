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
    std::queue<Node*> myQueue;
    int xsize;
    int ysize;
    Node source;
    Graph* graph;
    Node destination = source;
    //Node* createNeighbors(Node n);
public:
    BFS(int x, int y, Coordinate *source, Coordinate *destination);
    void getPath();
    void PrintPath(Node s, Node d);
    void visitNeighbors(Node& n);
    void setGraph(Graph *g);

};


/*
using namespace std;
class BFS {
private:
    queue<Node*> myQueue;
    int sizeX = 0;
    int sizeY = 0;
    Node source = Node();
    Node grid[10][10];
    Node destination = source;
    void visitNeighbors(Node &n);
    Node* createNeighbors(Node n);
public:
    BFS(int sizeX, int sizeY, Point source, Point destination);
    void getPath();
    void PrintPath(Node s, Node d);
};
*/

#endif //EXONE_BFS_H
