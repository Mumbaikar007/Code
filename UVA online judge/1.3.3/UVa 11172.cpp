//
// Created by optimus on 6/11/18.
//

# include <iostream>

using namespace std;

int main(){

    int testcases;
    cin >> testcases;

    int number1, number2;

    while (testcases--){

        cin >> number1 >> number2;
        cout << ( number1 > number2 ? ">" : ( number1 == number2 ? "=" : "<") ) << endl;
    }

    return 0;
}