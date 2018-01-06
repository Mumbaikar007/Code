//
// Created by optimus on 6/1/18.
//

# include <iostream>
# include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t -- ){

        int n;
        cin >> n;

        vector <long> vec(n), ans(n);

        for ( int i = 0 ;i < n ; i ++){
            cin >> vec[i] ;
        }

        ans[n-1] = 1;
        for ( int i = n-1; i >= 1; i --){
            ans[i-1] = ( vec[i] * vec[i-1] < 0 ) ? ans [i] + 1 : 1;

        }

        for ( int i = 0 ; i < n ; i ++)
            cout << ans[i] << " ";

        cout << endl;

    }


}