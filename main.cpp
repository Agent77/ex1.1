#include <iostream>
#include "Point.h"
#include "BFS.h"
#include "Node.h"
using namespace std;


int main() {
    queue<Node*> pq;
    Point p = Point(7,6);
    Point p2 = Point(1,4);
    //pq.push(p);
    Node n = Node(p);
    Node n2 = Node(p2);
    BFS bfs = BFS(n,n2, pq);
    bfs.getPath();
    return 0;
}
