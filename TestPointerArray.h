//
// Created by Tiki Lobel on 11/21/16.
//

#ifndef EX1_TESTPOINTERARRAY_H
#define EX1_TESTPOINTERARRAY_H


#include "Node.h"

class TestPointerArray {
public:
    TestPointerArray();
    Node* arrayOfPointerToNodes[3][3];
    Node** pointerToArrayOfPtrsToNodes = &arrayOfPointerToNodes[0][0];
    void TestMemory(Node** ptrToArray);
    void run();
};


#endif //EX1_TESTPOINTERARRAY_H
