//
// Created by optimus on 18/12/17.
//

# include <iostream>

using namespace std;

int main(){

    int bit;

    cin >> bit;


    if ( !bit == 0){
        cout << 32;
        return 0;
    }


    int currentLength = 0, previousLength = 0;
    int maxLength = 1;

    while ( bit ){

        if ( (bit & 1) == 1)
            currentLength ++;

        else {

            previousLength = ( bit & 2 == 0) ? 0 : currentLength;
            currentLength = 0;

        }

        maxLength = max ( maxLength, previousLength + currentLength + 1);
        bit >>= 1;
    }

    cout << maxLength;

    return 0;
}