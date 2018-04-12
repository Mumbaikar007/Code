//
// Created by optimus on 3/1/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main(){

    int n,a;
    cin >> n;

    vector <int> vec (n), maxil (n+1);
    for ( int i = 0 ; i < n ; i ++){
        cin >> a;
        vec[i] =  a;
        cout << vec[i] << " ";
    }
    cout << endl;
    maxil[0] = vec[0];
    cout << maxil[0] << " ";
    for ( int i = 1; i < n; i ++){
        maxil[i] = max ( vec[i], maxil[i-1] + vec[i]);
    }

    for ( int i = 1; i <= n+1; i ++){
        cout << maxil[i] << " ";

    }
    cout << endl;



    return 0;
}