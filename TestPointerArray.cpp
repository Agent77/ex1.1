//
// Created by Tiki Lobel on 11/21/16.
//

#include "TestPointerArray.h"
#include "Point.h"
//Node* arrayOfPointerToNodes[3][3];
//Node** pointerToArrayOfPtrsToNodes = &arrayOfPointerToNodes[0][0];
//void TestMemory(Node** ptrToArray);
TestPointerArray::TestPointerArray() {

}
void TestPointerArray::TestMemory(Node** ptrToArray) {
    Node* nodePtr = *(ptrToArray); //To 0,0
}

void TestPointerArray::run() {
    Node* arrayOfPointerToNodes[3][3];
    Node** pointerToArrayOfPtrsToNodes = &arrayOfPointerToNodes[0][0];
    Point point = Point(1,4);
    Point* p = &(point);
    Node node = Node(p);
    Node* n = &node;
    arrayOfPointerToNodes[0][0] = n;//Adding a pointer to place 0,
    pointerToArrayOfPtrsToNodes[0][1] = *n; // adding a Node same way as above
    pointerToArrayOfPtrsToNodes++; //What does this do?
    *pointerToArrayOfPtrsToNodes = n; // Where does it put n?
    std::cout << "Array:"<< arrayOfPointerToNodes << std::endl;
    std::cout<< "Pointer to Array: "<< pointerToArrayOfPtrsToNodes;
    TestPointerArray tester = TestPointerArray();
    tester.TestMemory(pointerToArrayOfPtrsToNodes);
    //pointerToArrayOfPtrsToNodes[
    // print first thing pointerToArrayOfPtrsToNodes
}