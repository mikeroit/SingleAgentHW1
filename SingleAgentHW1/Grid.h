//
// Created by mikeroit on 3/29/2016.

//IMPLICIT implementation of 2d grid domain

#ifndef SINGLEAGENTHW1_GRID_H
#define SINGLEAGENTHW1_GRID_H

#endif //SINGLEAGENTHW1_GRID_H

#include <stdint.h>
#include <iostream>
#include <vector>

//Grid class implements all elements of 2d grid domain

//"MyState", as introduced in the sample code, is simply
//represented by a 32-bit integer. The upper 16 bits determine
//the x-loc, the lower 16 bits determine the y-loc.

//-------------------------------------------------------------------------
class Grid {

public:
//  Default constructor will generate a 100x100 grid
    Grid(){sideLen = 100;}
//  Given size param, this constructor sets the given sideLen
    Grid(int size){sideLen = size;}

//  public functions utilized by algorithm
    void GetActions(uint32_t &nodeID, std::vector<int> &actions);
    void ApplyAction(uint32_t &s, int action);
    void UndoAction(uint32_t &s, int action);

private:
//  Given the implicit nature of the problem, the only required info
//  to describe the domain is a side length (square domains only)
    int sideLen;

//  Private methods will be used to parse the node addresses from uint32_t
//  --> x/y values
    int getX(uint16_t &nodeID);
    int getY(uint16_t &nodeID);

};
//-------------------------------------------------------------------------