//
// Created by optimus on 17/11/17.
//

# include <iostream>
#include <stack>

using namespace std;

int main(){

    stack <int> sNew, sOld;

    // Add elements to stack new

    int num;
    for ( int i = 0 ; i < 5; i ++) {
        cin >> num;
        sNew.push(num);

    }


    // reverse stackNew if stackOld is empty
    if ( sOld.empty()) {
        while (!sNew.empty()) {
            sOld.push(sNew.top());
            sNew.pop();
        }
    }


    // Removing from queue : pop from stack old

    cout << "Removing " << sOld.top();
    sOld.pop();




    return 0;
}