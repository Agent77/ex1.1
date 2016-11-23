#include "BFS.h"

using namespace std;
/*
 * Initializes the BFS source and destination based
 * on input, and sets the BFS graph to the graph object
 * that was sent.
 */
BFS::BFS(Graph* g, int x, int y, Coordinate* sLoc, Coordinate* dLoc) {
    xsize = x;
    ysize = y;
    source =  g->getNode(sLoc);
    (*(source)).visit();
    (*(source)).setPrev(*source);
    destination = g->getNode(dLoc);
    graph = g;
}
/*
 * Prints the path from Source to Destination by
 * working backwards, from destination, and asking for the
 * node's 'previous' until arriving at the source.
 */
void BFS::PrintPath( Node* source, Node* destination) {
    Coordinate* path[100] = {};
    int count = 0;
    Node* currentNode = destination;
    path[count] = ((*(currentNode)).getLocation());
    count++;
    Node* n;
    do {
         n = ((*(graph)).getLocationOfPrev(currentNode));
        //Will break from loop if arrived back at source
        if (n->getLocation()->equalTo(source->getLocation())) {
            path[count] = n->getLocation();
            break;
        }
        path[count] = n->getLocation();
        count++;
        //n is the previous currentNode's 'previous'
        currentNode = n;
    } while(!(currentNode->getLocation()->equalTo(source->getLocation())));

    for(int i = count; i >= 0; i--) {
        Point p(path[i]);
        cout<<p<<endl;
    }
}

/*
 * Gets the path from a source to a destination using a queue.
 * each iteration, it checks if it has arrived the destination.
 * Once it breaks, it prints the path.
 */
void BFS::getPath() {
    Node* newSource;
    Coordinate *c1;
    Coordinate *c2;
    myDeque.push(source);
    newSource = source;
    do {
        visitNeighbors(newSource);
        if (!myDeque.empty()) {
            myDeque.pop();
        }
        newSource = myDeque.front();
        c1 = (*(newSource)).getLocation();
        c2 = (*(destination)).getLocation();
} while(!(c2->equalTo(c1)));
BFS::PrintPath(source, destination);
}

/*
 * Function visits all the neighbors of the sent node, n, by calling
 * the node's function 'getNeighbors()'. It then iterates
 * over the vector of neighbors, to check if they've been visited.
 * If they haven't, its sets their member 'visited' to true and
 * pushes them onto the queue.
 */
void BFS::visitNeighbors(Node* n) {
    std::vector<Node*> neighbors = (*(graph)).getNeighbors(n);
    vector<Node*>::iterator v =neighbors.begin();
    while (v!=neighbors.end()){
        if (!(*(*v)).isVisited()){
            (*(*v)).visit();
            myDeque.push((*v));
        }
        v++;
    }
}