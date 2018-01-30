//
// Created by optimus on 30/1/18.
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

        vector <int> vec(n-1);

        for ( int i = 0 ; i < n ; i ++)
            cin >> vec[i];

        int start = 10000, end = n-1, temp = 1 ;
        int sum = 0, ans = 0;
        for ( int i = 0 ; i < n-1; i ++){
            sum += vec[i];
            if ( sum < 0 ){
                sum = 0;
                temp = i + 1;
            }

            if  ( sum > ans || (sum == ans && ( i+1 - temp ) > ( end - start) )){
                start = temp;
                end = i+1;
                sum = ans;
            }
        }

        if ( ans > 0 ){
            cout << "The nicest part of route %d is between stops " << start << " and " << end << "\n";
        }
        else {
            cout << "Route " << n << " has no nice parts\n";
        }

    }

    return 0;
}