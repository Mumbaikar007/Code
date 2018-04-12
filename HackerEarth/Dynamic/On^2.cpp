//
// Created by optimus on 4/1/18.
//

#include<bits/stdc++.h>
using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;


    vector < vector<long long> > vec (101, vector <long long> (10001) );


    //vector <long long > vecK (K+1);
    //iota ( begin(vecK), end(vecK), 0);

    for ( int i = 1 ; i < 101; i ++){

        vec[i][0] = 1;

        for ( int j = 1 ; j < 10001; j ++ ){

            for ( int k = 1; k <= min (i, j) ; k ++  ){
                vec[i][j] += vec[i][j-k];
                vec[i][j] %= 1000000007;
            }

        }


    }

    for ( int i = 0 ; i < 10; i ++){
        for ( int j = 0 ; j < 10; j ++)
            cout << vec[i][j] << " ";
        cout << endl;
    }


    for(int t_i=0; t_i<T; t_i++)
    {
        long long N;
        cin >> N;
        long long K;
        cin >> K;

        long long out_;

        cout << vec[K][N];

        cout << "\n";
    }
}