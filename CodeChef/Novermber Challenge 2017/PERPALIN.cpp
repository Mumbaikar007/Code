//
// Created by optimus on 8/11/17.
//

# include <string>
#include <iostream>

using namespace std;

string permute( string str, int l, int r ){

    if ( l == r ){

        int palin = 1;
        for ( int i = 0 ; i < str.size()/2 ; i ++){
            if ( str[i] != str[str.size() - 1 - i]){
                palin = 0;
                break;
            }
        }
        return ( palin ) ? str : "N";
    }

    else {
        string aa = "ab";
        for ( int i = 0 ; i < aa.size(); i ++){
            swap ()
        }
    }

}

int main(){

    int t;
    cin >> t;

    while (t --){

        int n, p;
        cin >> n >> p;

        string pal =

    }

    return 0;
}

