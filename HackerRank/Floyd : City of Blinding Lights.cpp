//
// Created by optimus on 3/12/17.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int nodes, edges;
    cin >> nodes >> edges;

    vector < vector <int> > distance(nodes, vector<int>(nodes)) ;

    int a, b, r;
    for ( int i = 0; i < edges; i++ ){
        cin >> a >> b >> r;
        distance[a-1][b-1] = r;
    }

    for ( int i = 0 ; i < nodes; i ++)
        distance[i][i] = 0;

    int i, j , k;

    for ( k = 0 ; k < nodes; k ++){
        for ( i = 0 ; i < nodes; i ++){
            for ( j = 0 ; j < nodes; j ++){

                if ( distance[i][k] + distance[k][j] < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }


            }
        }
    }


    int q;
    cin >> q;

    while ( q--){
        cin >> a >> b;
        cout << ( distance[a-1][b-1] == 800 ? -1: distance[a-1][b-1]) << endl;
    }




    return 0;
}