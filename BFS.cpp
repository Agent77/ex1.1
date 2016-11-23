#include "BFS.h"

using namespace std;

BFS::BFS(Graph* g, int x, int y, Coordinate* sLoc, Coordinate* dLoc) {
    xsize = x;
    ysize = y;
    source =  g->getNode(sLoc);
    (*(source)).visit();
    (*(source)).setPrev(*source);
    destination = g->getNode(dLoc);
    //Node node = Node();
    //source.setPrev(&node);
    graph = g;
}

void BFS::PrintPath( Node* source, Node* destination) {
    Coordinate* path[100] = {};
    int count = 0;
    Node* currentNode = destination;
    path[count] = ((*(currentNode)).getLocation());
    count++;
    Node* n;
    //When we get to source, add and then exit
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

    //while (!(((*(currentNode)).getLocation()->equalTo(source->getLocation())))) {
    for(int i = count; i >= 0; i--) {
        Point p(path[i]);
        cout<<p<<endl;
    }
}
void BFS::getPath() {
    Node* newSource;
    Coordinate *c1;
    Coordinate *c2;
    Node* prev;
    myDeque.push(source);
    newSource = source;
    do {
        visitNeighbors(newSource);
        if (!myDeque.empty()) {
            myDeque.pop();
            std::cout<<"next one";
            std::cout<<myDeque.front()->getLocation()->getNextCoordinate(0);
            std::cout<<myDeque.front()->getLocation()->getNextCoordinate(1)<<std::endl;
            std::cout<<"Prev:";
            std::cout<<myDeque.front()->getPrev()->getLocation()->getNextCoordinate(0);
            std::cout<<myDeque.front()->getPrev()->getLocation()->getNextCoordinate(1)<<std::endl;
        }
        //if(newSource->getLocation()->equalTo(destination->getLocation())) {
          //  destination->setPrev(*newSource);
            //break;
        //}

        newSource = myDeque.front();
         //Points to next Node in queue
        c1 = (*(newSource)).getLocation();
        c2= (*(destination)).getLocation();
} while(!(c2->equalTo(c1)));//TODO make sure this works
    //visitNeighbors(destination);
    //destination->setPrev(*prev);
BFS::PrintPath(source, destination);

}
void BFS::visitNeighbors(Node* n) {
    std::vector<Node*> neighbors = (*(graph)).getNeighbors(n);
    int num = (*(n)).numOfNeighbors();
    int i;
    //int size = (int)sizeof(neighbors)/4;
    /**for ( i = 0; i < num; i++) {
        if (!((*(neighbors[i])).isVisited())) {
            ((*(neighbors[i])).visit());
            myDeque.push(neighbors[i]);
        }
        else {
            ((*(neighbors[i])).setPrev(*n));
        }
    }*/
    vector<Node*>::iterator v =neighbors.begin();
    while (v!=neighbors.end()){
        if (!(*(*v)).isVisited()){
            (*(*v)).visit();
            myDeque.push((*v));
        }
        //else{
           // (*(*v)).setPrev(*n);
        //}
        v++;
    }
}
