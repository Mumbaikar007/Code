//
// Created by optimus on 11/1/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n, m;
    cin >> n >> m;

    vector <long long > vec(n);

    for ( long long i = 0 ; i < n ; i ++){
        cin >> vec[i];
    }


    long long r = 0, l = 0, sum = vec[0], maxil = 0;

    while ( r <= n){

        if ( sum <= m){
            maxil = max( maxil, sum);
            sum += vec[++r];
        }

        else {
            sum -= vec[l++];
        }

    }

    cout << maxil;

    return 0;

}