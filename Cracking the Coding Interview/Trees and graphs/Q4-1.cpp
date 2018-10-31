//
// Created by optimus on 25/11/17.
//

# include <iostream>
# include <queue>

using namespace std;

bool isPath (int AdjMat[10][10], int start, int end, int nodes){

    queue <int> queue1;
    int visited [10]  = {0};

    visited[start] = 1;

    queue1.push(start);

    while ( !queue1.empty() ){

        int currentNode = queue1.front();

        queue1.pop();

        for ( int i = 0 ; i < nodes; i ++){

            if ( AdjMat[currentNode][i] && !visited[i]){

                if ( i == end)
                    return true;

                queue1.push(i);
                visited[i] = 1;
            }

        }


    }

    return false;

}

int main(){

    int AdjMat[10][10];



    int nodes;
    cin >> nodes;


    for ( int i = 0 ; i < nodes; i ++){
        for ( int j = 0 ; j < nodes ; j ++)
            cin >> AdjMat[i][j];
    }


    int start, end;

    cout << ( isPath ( AdjMat, start, end, nodes)  ? "YES" : "NO" );


    return 0;
}