//
// Created by Tiki Lobel on 11/20/16.
//

#include "Coordinate.h"
/*
 * allows any function to request an objects location,
 * without having to know how many coordinates it contains
 * (ie, which dimension it is in)
 */
int Coordinate::getNextCoordinate(int i) {
    return locs[i];
}