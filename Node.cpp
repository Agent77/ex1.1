


#include "Node.h"

using namespace std;

Node::Node() {

}
Node::Node(Coordinate p) {
    myLocation = &p;
}
Coordinate* Node::getLocation() {
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
void Node::setPrev(Node& n) {
    prev = &n;
}