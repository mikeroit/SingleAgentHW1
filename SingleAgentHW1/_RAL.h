//
// Created by mikeroit on 4/1/2016.
//

//Roitman Algorithm Library

//Implementations:
//  Breadth-First search
//  Iterative-Deppening Depth-First search

#ifndef HW1_RAL_H
#define HW1_RAL_H

#endif //HW1_RAL_H
#include <iostream>
#include <cstdint>
#include <vector>
#include "simpleQ.h"
#include <algorithm>

using namespace std;

//--------------------------------------------   ***   Breadth First   ***   --------------------------------------------
//----------------------------------------------------------------------------------------------
template <typename environment>
class BFS{
public:
//  constructor
    BFS(environment *e, int goal);

private:

//  queues to manage space complexity during pathfinding
    simpleQ<uint32_t>* openList;
    simpleQ<uint32_t>* closedList;

//  total  number of expansions made during previous GetPath call
    uint64_t nodesExpanded;
};
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
template <typename environment>
BFS<environment>::BFS(environment *e, int goal){

//  initialize open/closed lists, nodesExpanded, start state
    openList = new simpleQ<uint32_t>();
    closedList = new simpleQ<uint32_t>();
    nodesExpanded = 0; openList->Add(0);

//  run BFS algorithm
    uint32_t stateToExpand = 0;
    std::vector<uint32_t> expandedNodes = {};

    while((openList->IsEmpty()) == false){

//      remove head of list and add to closed
        openList->Remove(stateToExpand); nodesExpanded++;
        cout << (stateToExpand >> 16) << ", " << (stateToExpand & 0x0000ffff) << endl;
        //openList->Print();
        //cout << endl;
        closedList->Add(stateToExpand);
        if(stateToExpand == goal) break;

//      expand removed node and add children to open
        std::vector<int> moves = {}; e->GetActions(stateToExpand, moves);
        for(int move : moves){

            if(move == 1){
                uint32_t temp = (((stateToExpand >> 16) + 1) << 16) | (stateToExpand & 0x0000ffff);
                if(std::find(expandedNodes.begin(), expandedNodes.end(), temp) == expandedNodes.end()){
                    openList->Add( temp );
                    expandedNodes.push_back(temp);
                }
            }

            if(move == e->getLen()){
                uint32_t temp = (stateToExpand + 1);
                if(std::find(expandedNodes.begin(), expandedNodes.end(), temp) == expandedNodes.end()){
                    openList->Add( temp );
                    expandedNodes.push_back(temp);
                }
            }

        }
    }

    cout << "Found goal after expanding " << nodesExpanded << " nodes" << endl;
};
//----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------


//---------------------------------------------   ***   Depth First   ***   ---------------------------------------------

//----------------------------------------------------------------------------------------------
//Depth - First iterative deepening algorithm
template <typename environment>
class DFID{
public:
//  constructor
    DFID(environment *e, uint32_t goal);

private:

    void DLS(environment *e, uint32_t state, uint32_t goal, int depth);

//  queues to manage space complexity during pathfinding
    simpleQ<uint32_t>* depthStack;


//  total  number of expansions made during previous GetPath call
    uint64_t nodesExpanded;
};

//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
template <typename environment>
DFID::DFID<environment>(environment *e, uint32_t goal){

}
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
template <typename environment>
void DFID<environment>::DLS(environment *e, uint32_t state, uint32_t goal, int depth){
    if(depth <= 0 || state == goal){
        return;
    }
    else if(depth > 0){
        std::vector<int> moves = {};
        e->GetActions(state, moves);

        for(int move: moves){
            if(move == 1){
                DLS( e, (((((state >> 16) + 1) << 16) | (state & 0x0000ffff))), goal, depth--);
            }

            if(move == e->getLen()){
                DLS(e, state++, goal, depth--);
            }
        }
        }
}

//----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------




















