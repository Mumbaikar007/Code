//
// Created by optimus on 9/2/18.
//

# include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int numOps(int n) {
    int result = 0;
    result += n/5;
    n %= 5;
    result += n/2;
    n %= 2;
    result += n;
    return result;
}

int main(){



    vector <int> ways (1000) ;
    iota (begin(ways), end(ways), 0);

    for ( int i = 2 ; i < 1000;i ++){
        ways [i] = min ( ways[i], 1+ways[i-2]);
    }

    for ( int i = 5 ; i < 1000;i ++){
        ways [i] = min ( ways[i], 1+ways[i-5]);
    }


    //for ( int i = 0 ; i < 100; i ++){
        cout << numOps(996) << " " << ways[996] << endl;
    //}




}