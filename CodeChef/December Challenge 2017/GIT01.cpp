//
// Created by optimus on 11/12/17.
//

# include <iostream>

using namespace std;

int main(){

    int t ;
    cin >> t;

    while ( t -- ){

        int n, m;
        cin >> n >> m;

        pair<int,int> even, odd;
        //cout << odd.first << " " << odd.second << endl;
        string abc;
        for ( int i = 0 ; i < n ; i ++){
            cin >> abc;
            for ( int j = 0 ; j < m ; j ++){
                if ( (i + j) % 2 ){
                    if ( abc.at(j) == 'R')
                        odd.first ++;
                    else
                        odd.second ++;
                }
                else{
                    if (abc.at(j) == 'R')
                        even.first ++;
                    else
                        even.second ++;
                }
            }
        }

        int minil = 0;


        if ( (even.second == 0 && odd.first == 0) || ( even.first == 0 && odd.second == 0)){
            ;
        }
        else if ( even.first < odd.first){
            minil += (even.first*5);
            minil += (odd.second*3);
            //cout << odd.first << " " << odd.first << " ";
        }
        else{
            minil += (odd.first*5);
            minil += (even.second*3);
        }

        cout << minil << endl;

    }



    return 0;
}