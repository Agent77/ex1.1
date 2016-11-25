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
int toInt(char* s);

int main() {

    int variables[7];
    char * input = new char();
    cin>>input;
    input = strtok(input, "_");
    for (int i = 0; i < 6; i++) {
        if (input != NULL) {
            variables[i] = toInt(input);
        }
        //Goes to next place where there is a '_' and splits
        if (input != NULL) {
            input = strtok(NULL, "_,");
        }
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

/*
 * converts the char to an int.
 */
int toInt(char* s) {
    //Could be 10
    if(*s - 48 == 1) {
        s++;
        if(*s - 48 == 0) {
            return 10;
        }
        else {
            return 1;
        }
    }
    return *s - 48;
}

