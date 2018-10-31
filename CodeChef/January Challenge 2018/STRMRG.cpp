//
// Created by optimus on 8/1/18.
//

# include <iostream>
# include <string>
#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--){

        int n, m ;
        cin >> n >> m;

        string a,b;
        cin >> a >> b;

        char preva = 65, prevb = 65;
        string ca = "", cb = "";

        for ( char i : a){
            if ( preva == i ){
                continue;
            }
            else{
                ca += i;
                preva = i;
            }

        }

        for ( char i : b){
            if ( prevb == i ){
                continue;
            }
            else{
                cb += i;
                prevb = i;
            }

        }


        //cout << ca << endl << cb << endl;

        vector <vector<int>> vec(2, vector <int> (ca.size()+1) );

        for ( int i = cb.size(); i >= 0 ; i --){

            int ii = i & 1;

            for (int j = ca.size(); j >= 0 ; j --){

                if ( i == cb.size() || j == ca.size()) {
                    vec[ii][j] = 0;
                    continue;
                }

                if ( ca[j] == cb[i] )
                    vec[ii][j] = 1 + vec[1-ii][j+1] ;

                else
                    vec[ii][j] = max( vec[ii][j+1], vec[1-ii][j]);

            }

        }

        cout << ca.size() + cb.size() - vec[0][0] << endl;



    }

    return 0;
}