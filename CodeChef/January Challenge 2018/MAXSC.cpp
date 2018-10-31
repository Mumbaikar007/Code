//
// Created by optimus on 5/1/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){

    int t ;
    cin >> t;

    while ( t-- ){
        int n;
        cin >> n;

        int gone = 0;
        vector <vector<long>> vec(n, vector<long> (n+1));
        long maxil;

        for ( int i = 0 ; i < n; i ++){
            maxil = 0;
            for ( int j = 0 ; j < n ; j ++){
                cin >> vec[i][j];
                maxil = max ( maxil, vec[i][j]);
            }
            vec[i][n] = maxil;
        }

        long long sum = vec[n-1][n];

        for ( int i = n-2; i >= 0; i--){

            if ( vec[i][n] < vec[i+1][n]){
                sum += vec[i][n];
                continue;
            }

            maxil = 0;
            int flag = 0;
            for ( int j = 0 ; j < n ; j ++){
                if ( vec[i][j] < vec[i+1][n] ){
                    maxil = max(vec[i][j], maxil);
                    flag = 1;
                }
            }

            if ( flag ){
                vec[i][n] = maxil;
                sum += maxil;
            }
            else {
                gone = 1;
                break;
            }

        }

/*
        for ( int i = 0 ; i < n ; i ++){
            for ( int j = 0 ; j < n+1 ; j ++)
                cout << vec[i][j] << " ";
            cout << endl;
        }
*/

        if ( gone )
            cout << -1 << endl;
        else
            cout << sum << endl;

    }


    return 0;
}