#include "BFS.h"

using namespace std;

BFS::BFS(Graph* g, int x, int y, Coordinate* sLoc, Coordinate* dLoc) {
    xsize = x;
    ysize = y;
    source =  g->getNode(sLoc);
    (*(source)).visit();
    destination = g->getNode(dLoc);
    //Node node = Node();
    //source.setPrev(&node);
    graph = g;
}
void BFS::setGraph(Graph *g) {//Set based off of input
    graph = g;
}

void BFS::PrintPath( Node source, Node destination) {
    Coordinate* path[100] = {};
    int count = 0;
    Node* currentNode = &destination;
    path[count] = ((*(currentNode)).getLocation());
    count++;
    while (!(((*(currentNode)).getLocation()->equalTo(source.getLocation())))) {
        currentNode = ((*(graph)).getLocationOfPrev(currentNode));
        path[count] = (*(currentNode)).getLocation();
        count++;
    }
    for(int i = count - 1; i >= 0; i--) {
        //cout<<path[i]<<endl;
    }
}
void BFS::getPath() {
    Node* newSource;
    Coordinate *c1;
    Coordinate *c2;
    myDeque.push(source);
    newSource = source;
    do {
        visitNeighbors(*newSource);
        if (!myDeque.empty()) {
            myDeque.pop();
        }
        newSource = myDeque.front();
         //Points to next Node in queue
        c1= (*(newSource)).getLocation();
        c2= (*(destination)).getLocation();
} while(!(c2->equalTo(c1)));//TODO make sure this works
BFS::PrintPath(*source, *destination);

}
void BFS::visitNeighbors(Node n) {
    Node* neighbors = (*(graph)).getNeighbors(n);
    int i;
    int size = (int)sizeof(neighbors)/4;
    for ( i = 0; i < size; i++) {
        if (!(neighbors[i].isVisited())) {
            myDeque.push(&neighbors[i]);
        }
        else {
            neighbors[i].setPrev(&n);
        }
    }
}
