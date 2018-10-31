//
// Created by optimus on 8/11/17.
//

# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t-- ){

        long n;

        long long r;
        cin >> n >> r;

        vector<long long> vec(n);

        for ( long i = 0 ; i < n ; i ++)
            cin >> vec[i];

        long long left = 0, right = 1000000001;

        int  flag = 0;
        for (long i = 0 ; i < n-1 ; i ++){

            if (vec[i] >= left && vec[i] <= right){

                if ( vec[i] < r )
                    left = vec[i];
                else
                    right = vec[i];

                //cout << left << " " << right << endl;
            }
            else {
                flag = 1;
                break;
            }

        }
        //cout << i << endl;
        cout << ( ( flag ) ? "NO" : "YES" ) << endl;

    }

    return 0;
}
