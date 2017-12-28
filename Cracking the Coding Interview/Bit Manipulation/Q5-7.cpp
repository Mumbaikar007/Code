//
// Created by optimus on 26/12/17.
//

# include <iostream>

using namespace std;

int main() {

    int a ;
    cin >> a ;

    cout << ( (a & 0xaaaaaaaa >>> 1) | ( a & 0x55555555 << 1) );

    return 0;
}