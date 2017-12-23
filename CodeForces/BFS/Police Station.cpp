//
// Created by optimus on 23/12/17.
//

# include <iostream>
#include <vector>
# include <queue>
using namespace std;

int n, k, d;
vector <int> visited;

void  BFS ( queue < pair < int, int> > &q, vector < vector <pair<int,int>> > &roads, vector <int> &needed){
    pair<int,int> p = q.front();

    if ( p.second != 0){
        for ( auto i : roads[p.first]){
            if (! visited[i.first]){
                needed[i.second]= 1;
                q.push ( make_pair( i.first, p.second-1));

            }
        }
    }


}

int main(){

    cin >> n >> k >> d;
    visited.resize(n);

    queue < pair < int, int> > q;
    vector < int> needed (n-1);
    int a;
    for ( int i = 0 ; i < k ; i ++){
        cin >> a;
        a--;
        visited [a] = 1;
        q.push( make_pair( a, d));
    }

    int b;
    vector < vector < pair<int,int>> > roads (n);


    for ( int i = 0 ; i < n-1; i ++){
        cin >> a >> b;
        a--; b--;
        roads[a].push_back(make_pair(b, i));
        roads[b].push_back(make_pair(a, i));
    }

    while ( !q.empty() ){
        BFS( q, roads, needed );
        q.pop();
    }

    return 0;
}