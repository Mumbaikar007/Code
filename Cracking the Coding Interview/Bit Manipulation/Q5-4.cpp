//
// Created by optimus on 26/12/17.
//

# include <iostream>

using namespace std;

int main(){

    int a, b;

    int count = 0;
    for ( int c = a ^ b ; c != 0; c = c & ( c - 1) )
        count ++;

    cout << count;


    return 0;
}