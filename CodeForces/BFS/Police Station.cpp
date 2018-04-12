//
// Created by optimus on 23/12/17.
//

# include <iostream>
#include <vector>
# include <queue>

struct Constrains {
    int dist, next, road;
};

using namespace std;

int main() {

    int n, m, k;

    cin >> n >> m >> k ;

    vector < vector<pair <int,int> > adjList (n+1);
    vector <int> visited (n+1), edges(k+1), police(k) ;
    int nodes = n;
    int a;
    for ( int i = 0 ; i < m ; i ++ ){
        cin >> a;
        police.push_back(a);
        visited[a] = 1;
        nodes --;
    }

    int b;
    for ( int i = 1 ; i <= n ; i ++){
        cin >> a >> b;
        adjList[a].push_back(make_pair(i,b));
        adjList[b].push_back(make_pair(i,a));
    }

    queue<int> q;
    for ( int i = 0 ; i < m && nodes; i ++){
        q.push(police[i]);

        while ( !q.empty() && nodes ){

        }
    }


    return 0;
}