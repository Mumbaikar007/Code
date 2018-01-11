//
// Created by optimus on 5/1/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){

    int t ;
    cin >> t;
    while ( t -- ){

        int n, k;
        cin >> n >> k;

        vector <long> vec(n);

        long long sum = 0;
        int neg  = 0;
        for (int i = 0 ; i < n ; i ++){
            cin >> vec[i];
            sum += vec[i];
            if ( sum < 0)
                neg = -1;
        }

        if ( neg < 0 ){
            long long m = 2*n;
            sum = 0;
            vector <long long> sums;
            for ( long long i = 0 ; i < m; i ++){
                sum += vec[i%n];
                if (sum < 0){
                    sums.push_back(sum);
                }
            }
        }

        else {
            cout << sum * k << endl;
        }





    }


    return 0;
}