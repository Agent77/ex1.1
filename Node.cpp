


#include "Node.h"

using namespace std;

Node::Node() {
    myLocation = Point(0,0);
}
Node::Node(Point p) {
    myLocation = Point(p.getX(), p.getY());
}
Point Node::getLocation() {
    return myLocation;
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
void Node::setPrev(Node& p) {
    prev = &p;
}