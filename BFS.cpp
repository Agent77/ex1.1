#include "BFS.h"

using namespace std;

BFS::BFS(Graph* g, int x, int y, Coordinate* sLoc, Coordinate* dLoc) {
    xsize = x;
    ysize = y;
    source =  g->getNode(sLoc);
    (*(source)).visit();
    (*(source)).setPrev(*source);
    destination = g->getNode(dLoc);
    graph = g;
}

void BFS::PrintPath( Node* source, Node* destination) {
    Coordinate* path[100] = {};
    int count = 0;
    Node* currentNode = destination;
    path[count] = ((*(currentNode)).getLocation());
    count++;
    Node* n;
    do {
         n = ((*(graph)).getLocationOfPrev(currentNode));
        if (n->getLocation()->equalTo(source->getLocation())) {
            path[count] = n->getLocation();
            break;
        }
        path[count] = n->getLocation();
        count++;
        currentNode = n;
    } while(!(currentNode->getLocation()->equalTo(source->getLocation())));
    for(int i = count; i >= 0; i--) {
        Point p(path[i]);
        cout<<p<<endl;
    }
}
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
        c2= (*(destination)).getLocation();
} while(!(c2->equalTo(c1)));//TODO make sure this works
BFS::PrintPath(source, destination);

}
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