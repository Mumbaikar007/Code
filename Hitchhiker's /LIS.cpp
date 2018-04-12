//
// Created by optimus on 4/2/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){


    int n;
    cin >> n;

    vector<int> vec(n), m(n);

    for ( int i = 0 ; i < n ; i ++)
        cin >> vec[i];


    for ( int i = n-1; i >= 0; i --){
        m[i] = 1;
        for ( int j = i + 1; j < n ; j ++){
            if ( vec[j] > vec[i] )
                m[i] = max (m[i], m[j] + 1);
        }
    }

    cout << m[0] ;

    return 0;
}