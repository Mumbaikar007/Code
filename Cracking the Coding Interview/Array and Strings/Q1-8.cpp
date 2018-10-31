//
// Created by optimus on 10/11/17.
//

# include <iostream>
# include <string>
#include <vector>

using namespace std;

int main(){

    int r, c;
    cin >> r >> c;

    vector < vector <int> > vec ( r, vector<int> (c));

    for  (int i = 0 ; i < r ; i ++){
        for ( int j = 0 ; j < c; j ++)
            cin >> vec[i][j];
    }


    int row0 = 0, col0 = 0;


    for ( int i = 0 ; i < c ; i ++ ){
        if ( vec [0][i] == 0)
            col0 = 1;
    }

    for ( int i = 0 ; i < r ; i ++){
        if ( vec[i][0] == 0)
            row0 = 1;
    }

    // set<int> rset, cset;

    for ( int i = 1 ;i < r ; i ++ ){
        for ( int j = 1 ; j< c ; j ++){
            if ( !vec[i][j] ){

                vec[i][0] = 0;
                vec[0][j] = 0;

                //rset.insert(i);
                //cset.insert(j);

            }
        }
    }


    for ( int i = 0 ; i < r ; i ++){

        if ( !vec[i][0]){
            for ( int j = 0 ; j < c ; j ++)
                vec[i][j] = 0;
        }

    }

    for ( int i = 0 ; i < c ; i ++){

        if ( !vec[0][i]){
            for ( int j = 0 ; j < c ; j ++)
                vec[j][i] = 0;
        }

    }

    for ( int i = 0 ; i < r ; i ++){
        for ( int j = 0 ; j < c; j ++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    return 0;
}

