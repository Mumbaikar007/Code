//
// Created by optimus on 22/12/17.
//


# include <iostream>
#include <vector>
#include <queue>
# include <algorithm>
#include <set>

using namespace std;

int main(){

    int n, m , k;
    cin >> n >> m >> k;

    vector <vector<int>> vec (n);

    int a, b;

    for ( int i = 0; i < m ; i ++){
        cin >> a >> b;
        vec[a-1].push_back(b-1);
        vec[b-1].push_back(a-1);
    }
    //cout << vec[0].size() << endl;
    if ( (n - vec[0].size() - 1) != k){
        cout << "impossible";
    }

    else {


        set<int> Set;
        for ( int i = 2; i < n ; i ++)
            Set.insert(i);

        //int nodes = n - 1 ;
        vector <int> visited(n);

        queue<int> q;
        q.push(0);
        //visited[0] = 1;



        while ( !q.empty() ){

            int j = q.front();
            q.pop();

            vector<int> no(n);
            for ( auto i : vec[j]) {
                no[i] = 1;
            }

            for ( int i : Set ){
                if ( !visited[i] && !no[i] ){
                    //cout << i << " ";
                    //visited[i] = 1;
                    Set.erase(i);
                    //nodes -- ;
                    q.push(i);
                }
                //cout << endl;
            }

        }
        //cout << nodes << endl;
        cout << ( Set.size() != 0 ? "impossible" : "possible" ) ;
    }

    return 0;
}