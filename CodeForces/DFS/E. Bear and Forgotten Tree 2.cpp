//
// Created by optimus on 21/12/17.
//

# include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n, m , k;
    cin >> n >> m >> k;

    vector <vector<int>> vec ( n    , vector<int> (n, 1) );

    int a, b;

    for ( int i = 0; i < m ; i ++){
        cin >> a >> b;
        vec[a-1][b-1] = vec[b-1][a-1] = 0;
    }

    for ( int i = 0; i < n ; i ++) {
        vec[i][i] = 0;
    }

    for ( int i = 0 ; i < n; i ++){

        if ( vec[0][i] )
            k--;
    }

    if ( k != 0 ){
        cout << "impossible";
    }

    else {
        int nodes = n-1;
        vector <int> visited(n);

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while ( !q.empty() ){

            int j = q.front();
            q.pop();


            for ( int i = 0 ; i < n ; i ++){

                if ( !visited [i] && vec[i][j]){
                    visited[i] = 1;
                    nodes --;
                    //cout << i << endl;
                    q.push(i);
                }
            }
        }

        cout << ( nodes ? "impossible" : "possible" ) ;
    }

    return 0;
}