#include <iostream>
#include "Point.h"
#include "BFS.h"
#include "Node.h"
#include "Graph.h"
#include "Grid.h"
using namespace std;


int main() {
    Point p = Point(1,0);
    Point p2 = Point(1,2);
    Graph* graphPointer;
    Grid g = Grid(3, 3);
    graphPointer = &g;
    BFS bfs = BFS(3, 3, &p, &p2);
    bfs.setGraph(graphPointer);
    bfs.getPath();
    return 0;
}
