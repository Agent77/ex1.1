/*
 * The main class of the project is in charge of parsing the input and creating the relevant
 * objects. then calling the method of the BFS in order to get the right path.
 */

#include <iostream>
#include "Point.h"
#include "BFS.h"

using namespace std;

int main() {

    char input[12];
    cin>>input;
    int xSize = input[0] - 48;
    int ySize = input[2] - 48;
    int startX = input[4] - 48;
    int startY = input[6] - 48;
    int endX = input[8] - 48;
    int endY = input[10] - 48;
    Point p1 = Point(startX,startY);
    Point p2 = Point(endX,endY);
    Graph* graphPointer;
    Grid g = Grid(xSize, ySize);
    graphPointer = &g;
    BFS* bfs = new BFS(graphPointer, xSize, ySize, &p1, &p2);
    bfs->getPath();
    delete bfs;
    return 0;
}


