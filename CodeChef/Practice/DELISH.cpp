//
// Created by optimus on 11/1/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){


    int t;
    cin >> t;

    while ( t -- ){

        int n;
        cin >> n;
        vector <long long> vec(n);
        for ( int i = 0 ; i < n ;  i++)
            cin >> vec[i];

        vector <long long> minL (n), maxL(n), minR(n), maxR(n);

        minL[0] = maxL[0] = vec[0];

        for ( int i = 1 ; i < n ; i ++){
            minL[i] = min ( vec[i] , minL[i-1] + vec[i] );
            maxL[i] = max ( vec[i] , maxL[i-1] + vec[i] );
        }

        minR[n-1] = maxR[n-1] = vec[n-1];

        for ( int i = n-2; i >= 0 ; i --){
            minR[i] = min ( vec[i] , minR[i+1] + vec[i] );
            maxR[i] = max ( vec[i] , maxR[i+1] + vec[i] );
        }

        long long maxil = 0;

        for ( int i = 0 ; i < n-1; i ++){
            maxil = max ( maxil, abs(maxL[i] - minR[i+1]));
            //cout << abs(maxL[i] - minR[i+1]) << " " ;
            maxil = max ( maxil, abs ( minL[i] - maxR[i+1]));

        }
                //cout << endl;

        cout << maxil << endl;

    }

    return 0;
}