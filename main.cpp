#include <iostream>
#include "Point.h"
#include "BFS.h"
#include "Node.h"
#include "Graph.h"
#include "Grid.h"
#include "TestPointerArray.h"
using namespace std;

int main() {
    //TestPointerArray test = TestPointerArray();
    //test.run();
    Point p = Point(0,0);
    Point p2 = Point(1,2);
    Graph* graphPointer;
    Grid g = Grid(3, 3);
    graphPointer = &g;
    BFS bfs = BFS(graphPointer, 3, 3, &p, &p2);
    bfs.setGraph(graphPointer);
    bfs.getPath();
    return 0;
}
