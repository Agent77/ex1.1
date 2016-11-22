


#include "Node.h"

using namespace std;

Node::Node() {
    visited = false;
}
Node::Node(Coordinate *p) {
    myLocation = p->getCoordinates();
    visited = false;
}
Coordinate* Node::getLocation() {//TODO changes made here now
    return myLocation->getCoordinates();
}
bool Node::isVisited() {
    return visited;
}
void Node::visit() {
    visited = true;
}
Node* Node::getPrev() {
    return prev;
}
void Node::setPrev(Node* n) {
    prev = n;
}
