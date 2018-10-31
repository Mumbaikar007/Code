//
// Created by optimus on 10/11/17.
//

# include <iostream>
# include <string>
# include <vector>

using namespace std;


int main(){

    int r, c;
    cin >> r >> c;

    vector< vector<int> > mat ( r );
    for ( int i = 0 ; i < r; i ++)
        mat[i].resize(c);


    for ( int i = 0 ; i < r ; i ++){
        for ( int j = 0 ; j < c ; j ++){
            cin >> mat[i][j];
        }
    }


    if ( r != c || mat.size() == 0)
        cout << "NO";

    else {

        for ( int i = 0 ; i < r/2 ; i ++){

            for ( int j = i ; j < (c - 1  - i); j ++){

                int temp = mat[i][j];
                mat[i][j] = mat[c-1-j][i];
                mat[c-1-j][i]= mat[c-1-i][c-1-j];
                mat[c-1-i][c-1-j] = mat[j][c-1-i];
                mat[j][c-1-i] = temp;
            }

        }

        for ( int i = 0 ; i < r ; i ++){
            for ( int j = 0 ; j < c ; j ++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }


    return  0;
}