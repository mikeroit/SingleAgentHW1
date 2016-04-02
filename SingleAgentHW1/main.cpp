#include <iostream>
#include <cmath>
#include "simpleQ.h"
#include "Grid.h"
#include "_RAL.h"


using namespace std;

int main() {


//-----------------------------------------   *** TESTING FOR 'simpleQ' *** -----------------------------------------

//  1) make a simpleQ to test on
    simpleQ<int> *testQ = new simpleQ<int>();
    cout << "testQ initialized . . ." << endl << endl;


//  2) populate queue, test that values are correct
    cout << "populating testQ with 10 items: (Even numbers [0, 20])" << endl;
    for(int i = 0; i < 10; i++){
        cout << "adding " << (2 * i) << endl;
        testQ->AddHead((2 * i));


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


//-----------------------------------------   *** TESTING FOR 'Grid::GetActions' *** --------------------------------

//  0) make a Grid to test on
    Grid testG = Grid(100);

//  make a place to store actions
    std::vector<int> myActions = {};

//  ----------------------------------------------------------------------------
//  test non-corner cases:
        uint32_t eight_eight = ((8 << 16) | 8);
        uint32_t nine_twelve = ((9 << 16) | 12);
        uint32_t seventy_eightynine = ((70 << 16) | 89);

        cout << "Testing non-corner cases using: \n(8,8), (9,12)" << endl;

//      test (8,8)
        testG.GetActions(eight_eight, myActions);
        cout << "Legal moves generated for (8,8):" << endl;
        for(int n : myActions){
            cout << n << " ";
        }
        myActions.clear();
        cout << endl;

//      test (9,12)
        testG.GetActions(nine_twelve, myActions);
        cout << "Legal moves generated for (9,12):" << endl;
        for(int n : myActions){
            cout << n << " ";
        }
        myActions.clear();
        cout << endl;
        cout << endl;
//  ----------------------------------------------------------------------------

//  ----------------------------------------------------------------------------
//  corner case one: literal corners of Grid [(0,0) (99,0) (0,99) and (99,99)]
        uint32_t zero_zero = (0); //should return move(s) (1 and 100)
        uint32_t ninenine_zero = ((99 << 16) | 0); //should return move(s) (100)
        uint32_t zero_ninenine = (99); //should return move(s) (1)
        uint32_t nintynine_ninetynine = ((99 << 16) | 99); //should return move(s) (empty set)
    cout << "Testing true-corner cases using: \n(0,0), (99,0) (0,99) (99,99)" << endl;


//      test (0,0)
        testG.GetActions(zero_zero, myActions);
        cout << "Legal moves generated for (0,0):" << endl;
        for(int n : myActions){
            cout << n << " ";
        }
        myActions.clear();
        cout << endl;

//      test (99,0)
        testG.GetActions(ninenine_zero, myActions);
        cout << "Legal moves generated for (99,0):" << endl;
        for(int n : myActions){
            cout << n << " ";
        }
        myActions.clear();
        cout << endl;

//      test (0,99)
        testG.GetActions(zero_ninenine, myActions);
        cout << "Legal moves generated for (0,99):" << endl;
        for(int n : myActions){
            cout << n << " ";
        }
        myActions.clear();
        cout << endl;

//      test (9,12)
        testG.GetActions(nintynine_ninetynine, myActions);
        cout << "Legal moves generated for (0,0):" << endl;
        for(int n : myActions){
            cout << n << " ";
        }
        myActions.clear();
        cout << endl;

//  ----------------------------------------------------------------------------




//-----------------------------------------   *** TESTING FOR BFS (Grid) *** --------------------------------

    Grid *testG2 = new Grid();
    BFS<Grid> *testBFS = new BFS<Grid>(testG2, 0x30003);

//-------------------------------------------------------------------------------------------------------------------
    return 0;
}