//
// Created by optimus on 8/1/18.
//

# include <iostream>

using namespace std;

int main(){

    int a = 1;
    int b = 10;
    int c = 1;
    int d = 100;

    int x = 5;
    int y = ( (double) (x-a) / (b-a) ) * (d-c) + c;

    cout << y;

    return 0;
}