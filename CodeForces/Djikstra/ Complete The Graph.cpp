//
// Created by optimus on 3/1/18.
//

# include <iostream>
# include <algorithm>

typedef pair < long long, long long > ii;
ii edge_list[100005];



using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, L, s, t;

    cin >> n >> m >> L >> s >> t;

    s ++;
    t ++;

    long long x, y, z;
    for ( long long i = 1 ; i <= m; i ++ ){
        cin >> x >> y >> z;
        x++; y ++;
    }

    return 0;
}