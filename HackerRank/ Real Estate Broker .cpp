//
// Created by optimus on 26/12/17.
//

#include <cmath>
#include <limits.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii client;
vii house;
int indexof(int i,int n,int buyer[])
{
    int inx=-1;
    int prc=INT_MAX;
    for(int j=0;j<n;j++)//client
    {
        if(buyer[j])
            continue;
        if(client[j].first<house[i].first && house[i].second<=client[j].second)
        {
            if(prc>client[j].second)
            {

                inx=j;
                prc=client[j].second;
            }

        }



    }
    return inx;
}
int solve(int n,int m)
{
    int sold[m]={0};
    int buyer[n]={0};
    int c=0;
    for(int i=0;i<m;i++)//house
    {
        int inx=indexof( i,n,buyer);
        if(inx>=0)
        {   c++;
            buyer[inx]=1;
        }


    }
    return c;

}
int main() {

    int n,m;
    cin>>n>>m;
    client.resize(n);
    house.resize(m);
    for(auto &x:client)
    {
        cin>>x.first>>x.second;
    }
    for(auto &x:house)
    {
        cin>>x.first>>x.second;
    }


    sort(house.begin(),house.end());
    cout<<solve(n,m);
    return 0;
}