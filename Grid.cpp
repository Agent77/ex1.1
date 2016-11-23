#include "Grid.h"
/*
 * The constructor initializes the grid with new Nodes,
 * which contain a Point of their location within
 * the grid.
 */
Grid::Grid(int xSize, int ySize) {
    sizeX = xSize;
    sizeY = ySize;
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            Point p = Point(i, j);
            Node* n;
            n = new Node(&p);//Creates a point
            arrayOfPtrsToNodes[i][j] = n;
        }
    }
}

/*
 * function returns a pointer to the previous Node, from which
 * we arrived at our current Node.
 */
Node* Grid::getLocationOfPrev(Node* n) {
    Node* prevNode = new Node(*(n->getPrev()));
    return prevNode;
}

/*
 * The function used the grid the get pointers to each
 * of the node's neighbors. Once it finds them,
 * if it hasn't been visited yet, it 'visits' them, and
 * sets their previous to be the node which was sent.
 * It returns them in a vector.
 */
std::vector<Node*> Grid::getNeighbors(Node* n) {
    //Vector to return with neighbors inside
    std::vector<Node*> neighbors;
    Coordinate* p = (*(n)).getLocation();
    //Copy constructor to convert the generic Coordinate to type Point
    Point point(p);
    int x = (point.getX());
    int y = (point.getY());
    //Left border of grid
    if ((x - 1) >= 0) {
        //9 o'clock neighbor
         Node* node = (arrayOfPtrsToNodes[(point.getX()) - 1][(point).getY()]);
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    //Top border of grid
    if (y + 1 < sizeY) {
        //12 o'clock neighbor
        Node* node = (arrayOfPtrsToNodes[(point).getX()][(point).getY() + 1]);
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    //Right border of grid
    if((x + 1) < sizeX) {
        //3 o'clock neighbor
        Node* node = arrayOfPtrsToNodes[(point).getX() + 1][(point).getY()];
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    //Bottom border of grid
    if((y - 1) >= 0) {
        //6 o'clock neighbor
        Node* node = arrayOfPtrsToNodes[point.getX()][point.getY() - 1];
        if(!(node->isVisited())){
            node->setPrev(*n);
            neighbors.push_back(node);
        }
    }
    return neighbors;
}
/*
 * Returns the appropriate Node in the same location in the
 * grid as the Node's location.
 */
Node* Grid::getNode(Coordinate* p){
    Node* node = (arrayOfPtrsToNodes[p->getNextCoordinate(0)][p->getNextCoordinate(1)]);
    return node;
}