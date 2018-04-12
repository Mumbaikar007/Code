//
// Created by optimus on 16/12/17.
//

# include <iostream>

using namespace std;

int main(){


    int n, m ;
    cin >> n >> m;


    int i, j ;
    cin >> i >> j ;


    int allOnes = !0;


    int left = allOnes << (j+1);

    int right = ( ( 1 << i ) - 1);

    int mask = left | right ;


    n = n & mask;

    m = m << i;

    cout << (n | m);




    return 0;
}