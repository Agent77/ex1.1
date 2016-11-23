#include <iostream>
#include "Point.h"
#include "BFS.h"
#include "Node.h"
#include "Graph.h"
#include "Grid.h"
#include "TestPointerArray.h"
using namespace std;

int main() {

    char* input;
    cin>>input;
    int xSize = *input - 48;
    input+=2;
    int ySize = *input - 48;
    input+=2;
    int startX = *input - 48;
    input+=2;
    int startY = *input - 48;
    input+=2;
    int endX = *input - 48;
    input+=2;
    int endY = *input - 48;
    Point p = Point(startX,startY);
    Point p2 = Point(endX,endY);
    Graph* graphPointer;
    Grid g = Grid(xSize, ySize);
    graphPointer = &g;
    BFS bfs = BFS(graphPointer, xSize, ySize, &p, &p2);
    bfs.getPath();
    return 0;
}


