#include "BFS.h"

using namespace std;

BFS::BFS(int x, int y, Coordinate *s, Coordinate *d) {
    xsize = x;
    ysize = y;
    source = Node(s);
    source.visit();
    destination = Node(d);
    Node node = Node();
    source.setPrev(node);
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
        currentNode = ((*(graph)).getLocationOfPrev(currentNode));//&(graph[(*(currentNode)).getPrev()->getLocation().getX()][(*(currentNode)).getPrev()->getLocation().getY()]);
        path[count] = (*(currentNode)).getLocation();
        count++;
    }
    //path[count] = source.getLocation();
    for(int i = count - 1; i >= 0; i--) {
        //cout<<path[i]<<endl;
    }
}
void BFS::getPath() {
    Node* newSource;
    myQueue.push(source);
    newSource = &myQueue.front();
    do {
        visitNeighbors(*newSource);
        if (!myQueue.empty()) {
            myQueue.pop(); //TODO erases wrong one!
        }
        newSource = &myQueue.front();
         //Points to next Node in queue
} while(!((*(newSource)).getLocation()->equalTo(destination.getLocation())));
BFS::PrintPath(source, destination);

}
void BFS::visitNeighbors(Node& n) {//TODO this belongs to graph, not BFS
    (graph)->print();
    Node* neighbors = (*(graph)).getNeighbors(&n);
    int i;
    for ( i = 0; i < sizeof(neighbors)/4; i++) {
        if (!(neighbors[i].isVisited())) {
            neighbors[i].visit();
            neighbors[i].setPrev(n); //TODO do anyway
            myQueue.push(neighbors[i]);
        }
        else {
            neighbors[i].setPrev(n);
        }
    }

    /*
    if ((n.getLocation().getX())- 1 >= 0) {
        neighbors = &(graph[(n.getLocation().getX()) - 1][n.getLocation().getY()]);
        count++;
    }
    if (((n.getLocation().getY()) + 1) < ysize) {
        neighbors++;
        neighbors = &(graph[n.getLocation().getX()][(n.getLocation().getY()) + 1]);
        count++;
    }
    if(((n.getLocation().getX()) + 1) < xsize) {
        neighbors++;
        neighbors = &(graph[(n.getLocation().getX()) + 1][(n.getLocation().getY())]);
        count++;
    }
    if((n.getLocation().getY()) - 1 >= 0) {
        neighbors++;
        neighbors = &(graph[(n.getLocation().getX())][(n.getLocation().getY()) - 1]);
    } */

}

/*Node* BFS::createNeighbors(Node n) {
    Node neighbors[4];
    //bool onXBorder = false;
    //bool onYBorder = false;
    //TODO check if off-grid
    //Off grid on x axis
    if((n.getLocation().getX() - 1 < 0) || (n.getLocation().getX() + 1 > 9)) {
        //onXBorder = true;
    }
    if((n.getLocation().getY() - 1 < 0) || (n.getLocation().getY() + 1 > 9)) {
        //onYBorder = true;
    }
    //if(//!(onYBorder || onXBorder)) {
    neighbors[0] = graph[(n.getLocation().getX()) - 1][n.getLocation().getY()];
    neighbors[1] = graph[n.getLocation().getX()][(n.getLocation().getY()) + 1];
    neighbors[2] = graph[(n.getLocation().getX()) + 1][(n.getLocation().getY())]; //TODO fix
    neighbors[3] = graph[(n.getLocation().getX())][(n.getLocation().getY()) - 1];

    //TODO check which border and add neighbors accordingly
    return neighbors;
}*/