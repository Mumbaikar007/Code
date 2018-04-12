//
// Created by optimus on 12/11/17.
//

# include <iostream>
# include <stack>
#include <climits>

using namespace std;

int main(){

    stack <int> smain, smins;
    int size, element;

    smins.push(INT_MAX);

    cout << "Enter number of elements ... ";
    cin >> size;

    cout << "Enter the elements ... \n";
    while ( size -- ) {
        cin >> element;
        smain.push(element);

        if ( element < smins.top() ){
            smins.push(element);
            cout << "Min is " << element << endl;
        }


    }

    cout << "Popping \n";

    //pop out elements
    while( !smain.empty() ){

        if ( smins.top() == smain.top() ){

            cout << "Min was " << smins.top() << endl;
            smins.pop();
        }

        smain.pop();
    }



    return 0;
}