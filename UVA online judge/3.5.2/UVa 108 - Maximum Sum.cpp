//
// Created by optimus on 3/2/18.
//

# include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int n;
    cin >> n ;

    vector<vector<int>> vec ( n, vector<int> (n));

    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < n ; j ++){
            cin >> vec[i][j];
            if ( i > 0 ) vec[i][j] += vec[i-1][j];
            if ( j > 0 ) vec[i][j] += vec[i][j-1];
            if ( i > 0 && j > 0 ) vec[i][j] -= vec[i-1][j-1];
        }
    }

    int maxil = -127*100*100;
    //cout << maxil << endl;

    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < n ; j ++){
            for ( int k = i ; k < n ; k ++){
                for ( int l = j ; l < n ; l ++){
                    int sumRect = vec[k][l];
                    if ( i > 0) sumRect -= vec[i-1][l];
                    if ( j > 0) sumRect -=vec[k][j-1];
                    if ( i > 0 && j > 0) sumRect += vec[i-1][j-1];
                    maxil = max ( maxil, sumRect);
                }
            }
        }
    }

    cout << maxil ;


    return 0;
}

