

#include "BFS.h"
using namespace std;

BFS::BFS(Node s, Node d, queue<Node*> &q) {
    source = s;
    source.setPrev(s);
    destination = d;
    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            graph[i][j] = Node(Point(i,j));
        }
    }
}

void BFS::PrintPath(Node source, Node destination) {
    Point path[100] = {};
    int count = 0;
    Node currentNode = destination;
    path[count] = (currentNode.getLocation());
    count++;
    while (!(((currentNode.getLocation() == source.getLocation())))) {
        currentNode = (*(currentNode.getPrev()));
        path[count] = (currentNode).getLocation();
        count++;
    } //DOESNT BREAK OUT!!
    //path[count] = source.getLocation();
    for(int i = count - 1; i >= 0; i--) {
        cout<<path[i]<<endl;
    }
}
void BFS::getPath() {
    Node* newSource = &source;
    myQueue.push(newSource);
    do {
        newSource->visit();
        visitNeighbors(*newSource);
        if (!myQueue.empty()) {
            myQueue.pop();
        }
        newSource = myQueue.front(); //Points to next Node in queue
    } while(!((*(newSource)).getLocation() == destination.getLocation()));
    BFS::PrintPath(source, destination);

}
void BFS::visitNeighbors(Node& n) {
    Node* neighbors;
    if (((n.getLocation().getX())- 1) >= 0) {
        neighbors = &(graph[(n.getLocation().getX()) - 1][n.getLocation().getY()]);
    }
    neighbors++;
    if (((n.getLocation().getY()) + 1) < 10) {
        neighbors = &(graph[n.getLocation().getX()][(n.getLocation().getY()) + 1]);
    }
    neighbors++;
    if(((n.getLocation().getX()) + 1) < 10) {
        neighbors = &(graph[(n.getLocation().getX()) + 1][(n.getLocation().getY())]);
    }
    neighbors++;
    if((n.getLocation().getY()) - 1 >=0) {
        neighbors = &(graph[(n.getLocation().getX())][(n.getLocation().getY()) - 1]);

    }
    //Node* nodePtr = createNeighbors(n);
    int i;
    for ( i = 0; i < 4; i++) {
        if (!(neighbors[i].isVisited())) {
            neighbors[i].visit();
            neighbors[i].setPrev(n);
            myQueue.push(&neighbors[i]);
            //TODO nodePtr[i].checkDest();
        }
    }
}

Node* BFS::createNeighbors(Node n) {
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
}



//Source.
//Visit neighbors, and add to queue -- function for this
//Check if reached destination
//update prev of all neighbors
//dequeue source
//Replace source with next in queue
