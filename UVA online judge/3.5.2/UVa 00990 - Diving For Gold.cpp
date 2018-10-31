//
// Created by optimus on 10/2/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){

    int t, w;



    while ( cin >> t >> w ){

        int n;
        cin >> n;

        vector <int> depth(n), value(n), time(n);
        vector<long long> dp(t+1);
        vector<int> count(t+1);
        vector <vector <int> > graph ( t+1, vector<int> (n));
        for ( int i = 0 ; i < n ; i ++){
            cin >> depth[i] >> value[i] ;
            time[i] = ( 3 * w ) * depth[i];
        }


        for ( int i = 0 ; i < n ; i ++){
            for ( int j = t; j > time[i]; j --){
                if ( dp[ j - time[i]] + value[i] > dp [j]){
                    dp [j] = dp[ j - time[i]] + value[i];
                    count[j] = count[j - time[i]] + 1;
                    graph[j][i] = 1;
                }
            }
        }

        cout << dp[t] << endl << count[t] << endl;

        for ( int i = 0, j = t; i < n ; i ++){
            if (graph[j][i] ){
                cout << depth[i] << " " << value[i] << endl;
                j -= time[i];
            }
        }

        cout << endl;
    }


    return 0;
}