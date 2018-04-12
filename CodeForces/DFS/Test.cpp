//
// Created by optimus on 22/12/17.
//

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
#define mod 1e9+7
const int N = 3e5 + 5;
int n , m , k;
set <int> nodes;
set < int > v[N];
int cnt;
int a , b;
int sz;
bool can(int a , int b){
    return v[a].find(b) == v[a].end();
}
void dfs(int node){
    vector < int > arr;
    for(int x : nodes){
        if(can(node , x)){
            arr.emplace_back(x);
        }
    }
    for(int x : arr){
        nodes.erase(x);
    }
    for(int x : arr){
        dfs(x);
    }
}
int main(){
    fast_io
    scanf("%d %d %d" , &n , &m , &k);
    cnt = n - 1;
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].insert(b);
        v[b].insert(a);
        cnt -= (min(a , b) == 1);
    }
    if(cnt < k){
        printf("impossible\n");
        return 0;
    }
    for(int i = 2 ; i <= n ; ++i){
        nodes.insert(i);
    }
    sz = 0;
    for(int i = 2 ; i <= n ; ++i){
        if(can(1 , i) && nodes.find(i) != nodes.end()){
            nodes.erase(i);
            dfs(i);
            ++sz;
        }
    }
    if(nodes.empty() && sz <= k){
        printf("possible\n");
    }
    else{
        printf("impossible\n");
    }
}