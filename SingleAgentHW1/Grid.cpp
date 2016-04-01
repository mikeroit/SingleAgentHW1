//
//Created by mikeroit on 3/29/2016.
//

#include <stdint.h>
#include "Grid.h"

//Constructors generic- implemented in "Grid.h"

//-------------------------------------------------------------------------
//Public Methods:

void GetActions(uint32_t &nodeID, std::vector<int> &actions){

//  fetch x and y coord of current state
    int x, y;
    x = getX(nodeID);
    y = getY(nodeID);

//  test to see if moving up/right is legal, add legal moves
    if(x + 1 < sideLen){
        actions.insert(x + 1);
    }
    if((y + 1) < sideLen){
        actions.insert(y + sideLen);
    }
}

void ApplyAction(uint32_t &s, MyAction a){

}

void UndoAction(uint32_t &s, MyAction a){

}

//-------------------------------------------------------------------------

//Private methods:

//Converts ID to x coord
int Grid::getX(uint16_t &nodeID){
    return (nodeID >> 16);
}

//Converts ID to y coord
int Grid::getY(uint16_t &nodeID){
    return (nodeID & 0x0000ffff);
}

