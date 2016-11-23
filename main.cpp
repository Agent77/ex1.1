/*
 * The main class of the project is in charge of parsing the input and creating the relevant
 * objects. then calling the method of the BFS in order to get the right path.
 */

#include <iostream>
#include "Point.h"
#include "BFS.h"

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
    Point p1 = Point(startX,startY);
    Point p2 = Point(endX,endY);
    Graph* graphPointer;
    Grid g = Grid(xSize, ySize);
    graphPointer = &g;
    BFS bfs = BFS(graphPointer, xSize, ySize, &p1, &p2);
    bfs.getPath();
    return 0;
}


