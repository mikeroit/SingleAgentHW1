#include <iostream>
#include <cmath>
#include "simpleQ.h"
#include "Grid.h"


using namespace std;

int main() {

/*
//-----------------------------------------   *** TESTING FOR 'simpleQ' *** -----------------------------------------

//  1) make a simpleQ to test on
    simpleQ<int> *testQ = new simpleQ<int>();
    cout << "testQ initialized . . ." << endl << endl;


//  2) populate queue, test that values are correct
    cout << "populating testQ with 10 items: (Even numbers [0, 20])" << endl;
    for(int i = 0; i < 10; i++){
        cout << "adding " << (2 * i) << endl;
        testQ->Add((2 * i));


    }
    cout << endl;

//  3) verify correct values
    cout << "Result of printing testQ:" << endl;
    testQ->Print();

    cout << endl;

//  4) pop all values from queue
    int temp = 0;
    cout << "Popping queue:" << endl;
    while(testQ->Remove(temp)){
        cout << "popped: " << temp << endl;
    }
//-------------------------------------------------------------------------------------------------------------------
*/


//-----------------------------------------   *** TESTING FOR 'Grid' *** --------------------------------------------

//  0) make a Grid to test on
    Grid testG = Grid(100);
    cout << testG.getLen();

//  1) test GetActions

//  make a place to store actions
    std::vector<int> myActions = {};

//  test non-corner cases:
    uint32_t eight_eight = ((8 << 16) | 8);
    uint32_t nine_twelve = ((9 << 16) | 12);
    uint32_t seventy_hundred = ((70 << 16) | 100);

    cout << "Testing non-corner cases using: \n (8,8), (9,12), (70,16)" << endl;
    testG.GetActions(eight_eight, myActions);
    cout << "Legal moves generated for (8,8):" << endl;
    for(int n : myActions){
        cout << n << ", ";
    }
    cout << endl;

//-----------------------------------------   *** TESTING FOR 'Grid' *** --------------------------------------------



//-------------------------------------------------------------------------------------------------------------------
    return 0;
}