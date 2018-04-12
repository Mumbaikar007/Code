//
// Created by optimus on 10/1/18.
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

        long long ss = n*k;

        vector <long> vec(n);

        long long sum = 0;
        int neg  = 0;
        for (int i = 0 ; i < n ; i ++){
            cin >> vec[i];
        }

        long long  max_so_far = 0, max_ending_here = 0;
        for ( long long  i = 0 ; i < ss; i ++){

            max_ending_here = max_ending_here + vec[i%n];
            if (max_ending_here < 0)
                max_ending_here = 0;
            if ( max_ending_here > max_so_far)
                max_so_far = max_ending_here;
        }


        cout << max_so_far << endl;
    }



    return 0;
}