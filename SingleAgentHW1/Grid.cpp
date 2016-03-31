//
//Created by mikeroit on 3/29/2016.
//

#include <stdint.h>
#include "Grid.h"

//Constructors generic- implemented in "Grid.h"

//-------------------------------------------------------------------------
//Public Methods:

void GetActions(uint32_t &nodeID, std::vector<MyAction> &actions){

    int x, y;
    x = getX(nodeID);
    y = getY(nodeID);

}

void ApplyAction(uint32_t &s, MyAction a){

}

void UndoAction(uint32_t &s, MyAction a){

}

//-------------------------------------------------------------------------

//Private methods:

int Grid::getX(uint16_t &nodeID){
    return (nodeID >> 16);
}

int Grid::getY(uint16_t &nodeID){
    return (nodeID & 0x0000ffff);
}

