//
// Created by optimus on 23/12/17.
//

# include <iostream>
# include <queue>
# include <climits>

using namespace std;

int main() {

    int n, m , k;
    cin >> n >> m >> k;
    //cout << n << m << k;
    vector<vector<char>> maze ( n, vector<char> (m));

    int sx, sy;
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ; j ++){
            cin >> maze[i][j];
            if ( maze[i][j] == 'X'){
                sx = i;
                sy = j;
            }
        }
    }


    queue < pair < int, int> > q;
    q.push ( make_pair( sx, sy));

    vector < vector<int> > distance (n, vector<int> (m,INT_MAX) );
    distance [sx][sy] = 0;

    int dx[4] = { 1, 0, 0, -1}, dy[4] = { 0, -1, 1, 0};
    char direction[4] = { 'D', 'L', 'R', 'U'};


    while ( !q.empty() ){

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for ( int i = 0 ; i < 4 ; i ++){

            int px = x + dx[i], py = y + dy[i];
            if ( px < 0 || py < 0 || px >= n || py >= m || maze[px][py] == '*')
                continue;

            if ( distance[px][py] > distance[x][y] + 1){
                distance[px][py] = distance[x][y] + 1;
                q.push( make_pair( px, py));
            }

        }

    }

    /*
    for ( int i = 0 ; i < n ; i ++){
        for ( int j = 0 ; j < m ; j ++)
            cout << distance [i][j] << " ";
        cout << endl;
    }
    */

    string s = "";
    for ( int i = k-1; i >= 0; i --){
        bool flag  = false;
        for ( int j = 0 ; j < 4 ; j ++){
            int px = sx + dx[j], py = sy + dy[j];
            //cout <<i << ": " << j << " - " <<  px << ", " << py;
            if ( px < 0 || py < 0 || px >= n || py >= m || distance[px][py] > i){
                continue;
            }

            s += direction[j];
            //cout << " " << s << endl;
            sx = px; sy = py;
            flag = true;
            //cout << py << ": " << sx << " " << sy << ": " << s << endl;
            break;

        }

        if ( !flag ) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    cout << s;

    return 0;
}