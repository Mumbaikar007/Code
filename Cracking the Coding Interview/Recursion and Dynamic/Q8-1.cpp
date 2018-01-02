//
// Created by optimus on 2/1/18.
//

# include <iostream>
#include <vector>

using namespace std;


int noOfWays ( int n, vector<int> &vec){
    if ( n < 0 )
        return 0;
    if ( n == 0)
        return 1;
    if ( vec[n] > -1)
        return vec[n];

    vec[n] = noOfWays( n-1, vec) + noOfWays( n-2, vec) + noOfWays( n-3, vec) ;
    return vec[n];

}

int main(){

    int n;
    cin >> n;

    vector <int> vec(n+1, -1);

    cout << noOfWays( n, vec) ;

    return 0;
}