//
// Created by optimus on 9/2/18.
//

# include <iostream>
#include <vector>
# include <cmath>

using namespace std;

int knap ( vector <int> vec, int sum ){

    vector <int> vec1(sum+1);

    //cout << "HAHA" << sum << endl;
    for (int i = 0 ; i < vec.size() ; i ++){

        for ( int j = sum; j > 0 ; j --){
            if ( vec[i] <= j)
                vec1[j] = max ( vec1[j], vec[i] + vec1[j-vec[i]]);
        }
    }

    return vec1[sum];
}

int main(){

    int t;
    cin >> t;

    while ( t--){

        int n;
        cin >> n;

        int sum = 0;
        vector <int> vec(n);
        for ( int i = 0 ; i < n ; i ++){
            cin >> vec[i];
            sum += vec[i];
        }

        //cout << knap ( vec, sum / 2) << endl;
        cout << ( sum - 2 * knap ( vec, sum / 2)) << endl;
    }

    return 0;
}