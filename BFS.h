//
// Created by Tiki Lobel on 11/17/16.
//
#include "Node.h"
#include <queue>


#ifndef EX1_BFS_H
#define EX1_BFS_H

using namespace std;
class BFS {
private:
    queue<Node*> myQueue;
    Node source = Node();
    Node graph[10][10];
    Node destination = source;
    void visitNeighbors(Node &n);
    Node* createNeighbors(Node n);
public:
    BFS(Node source, Node destination, queue<Node*> &q);
    void getPath();
    void PrintPath(Node s, Node d);
};


#endif //EXONE_BFS_H
