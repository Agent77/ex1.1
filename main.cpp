/*
 * The main class of the project is in charge of parsing
 * the input and creating the relevant
 * objects. then calling the method of the
 * BFS in order to get the right path.
 */

#include <iostream>
#include "Point.h"
#include "BFS.h"

using namespace std;

int main() {

    int variables[7];
    char * input;
    cin>>input;
    input = strtok(input, "_");
    for (int i = 0; i < 6; i++) {
        string s = input;
        variables[i] = std::atoi(input);
        //Goes to next place where there is a '_' and splits
        input = strtok(NULL, "_,");
    }
    Point start = Point(variables[2],variables[3]);
    Point end = Point(variables[4],variables[5]);
    Graph* graphPointer;
    //sizes sent to grid
    Grid g = Grid(variables[0],variables[1]);
    graphPointer = &g;
    BFS* bfs = new BFS(graphPointer, variables[0], variables[1], &start, &end);
    bfs->getPath();
    delete bfs;
    return 0;
}


