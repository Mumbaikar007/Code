//
// Created by optimus on 12/1/18.
//

# include <iostream>
# include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t-- ){

        int n;
        cin >> n;


        int maxil = 0;

        vector<int> H(n), K(n);

        for ( int i = 0 ; i < n ; i ++){
            cin >> H[i];
            maxil = max( maxil, H[i]);
        }

        //cout << maxil << endl;

        for ( int i = 0 ; i < n ; i ++){
            cin >> K[i];
        }

        //sort ( begin(K), end(K) );

        vector <int> dpMap (2*maxil + 1, INT_MAX);

        dpMap [0] = 0;

        for ( int i = 0 ; i < n ; i ++){

            for ( int j = K[i]; j <= 2*maxil + 1 ; j ++){
                dpMap[j] = min ( dpMap[j], 1 + dpMap[j-K[i]]);
            }

            /*
            cout << K[i] << ":" << endl;

            for ( int k = 0 ; k <= 2*maxil + 1 ; k ++){
                cout << dpMap[k] << " ";
            }

            cout << endl;
            */


        }

        long long sum = 0;
        for ( int i = 0 ; i < n ; i ++){
            sum += dpMap[H[i]*2];
            //cout << dpMap[H[i]*2] << " ";
        }



        cout << sum << endl;

    }

    return 0;
}