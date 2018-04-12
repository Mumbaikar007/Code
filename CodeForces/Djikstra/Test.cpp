//
// Created by optimus on 3/1/18.
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
typedef pair<long long, long long> ii;
//long long
long long edge_cost[10005];
struct Edge{
    long long to, edge_idx;
    bool operator<(const Edge& e)const{
        return edge_cost[edge_idx] > edge_cost[e.edge_idx];
    }
};

const long long INF = 1e18;   //long long으로 바꾸면 1e18로 해주기.
vector<Edge> a[1005];
long long dist[1005];
bool question[10005];
ii edge_list[100005];
long long n, m, L, s, t;
void init_dist(){
    for (long long i = 1; i <= n; i++){
        dist[i] = INF;
    }
}

void dijkstra(long long start){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    dist[start] = 0;
    q.push({ 0, start });
    while (!q.empty()){
        auto p = q.top();
        q.pop();
        long long node = p.second;
        long long ccost = p.first;
        if (dist[node] < ccost)
            continue;
        for (long long i = 0; i < a[node].size(); i++){
            long long next = a[node][i].to;
            long long cost = edge_cost[a[node][i].edge_idx];
            if (dist[next] > dist[node] + cost){
                dist[next] = dist[node] + cost;
                q.push({ dist[next], next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> L >> s >> t;
    s += 1, t += 1;
    for (int i = 1; i <= m; i++){
        long long x, y, z;
        cin >> x >> y >> z;
        x += 1, y += 1;
        edge_list[i] = { x, y };
        edge_cost[i] = z;
        a[x].push_back({ y, i });
        a[y].push_back({ x, i });
        if (z == 0){
            question[i] = true;
        }
    }
    for (long long i = 1; i <= m; i++){
        if (question[i])
            edge_cost[i] = 1;
    }
    init_dist();
    dijkstra(s);
    long long best = dist[t];

    for (long long i = 1; i <= m; i++){
        if (question[i])
            edge_cost[i] = INF;
    }
    init_dist();
    dijkstra(s);
    long long worst = dist[t];

    if (worst < L || best > L){
        cout << "NO";
        return 0;
    }
    for (long long i = 1; i <= m; i++){
        if (question[i]){
            edge_cost[i] = 1;
            init_dist();
            dijkstra(s);
            if (dist[t] <= L){
                edge_cost[i] = (L - (dist[t] - 1));
                break;
            }
        }
    }

    cout << "YES\n";
    for (long long i = 1; i <= m; i++){
        auto p = edge_list[i];
        cout << p.first-1 << " " << p.second-1 << " " << edge_cost[i] << "\n";
    }
    return 0;
}