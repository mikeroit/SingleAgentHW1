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

using namespace std;

//-------------------------------------------------------------------------------------------------------
template <typename state, typename action, typename environment>
class BREADTH_FIRST_PATHFIND{
public:
//  constructor
    BREADTH_FIRST_PATHFIND();

//  GetPath returns !(0) if the goal was found; ALWAYS STARTS (0,0)
    uint64_t GetPath(environment &e, state &goal);


private:

//  queues to manage space complexity during pathfinding
    simpleQueue* openList;
    simpleQueue* closedList;

//  total  number of expansions made during previous GetPath call
    uint64_t nodesExpanded;
};
//-------------------------------------------------------------------------------------------------------