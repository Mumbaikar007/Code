//
// Created by optimus on 19/2/18.
//

# include <iostream>
#include <vector>

using namespace std;

int main (){

    int n ;
    cin >> n ;

    while ( n --){

        string s;
        cin >> s;

        int size = s.size() - 4;

        int count = 0;

        for ( int i = 0; i < size; i ++){

            if ( s.at(i) == 'c' || s.at(i+1) == 'c' || s.at(i+2) == 'c' || s.at(i+3) == 'c' ){
                if ( s.at(i) == 'h' || s.at(i+1) == 'h' || s.at(i+2) == 'h' || s.at(i+3) == 'h' ){
                    if ( s.at(i) == 'e' || s.at(i+1) == 'e' || s.at(i+2) == 'e' || s.at(i+3) == 'e' ){
                        if ( s.at(i) == 'f' || s.at(i+1) == 'f' || s.at(i+2) == 'f' || s.at(i+3) == 'f' ){
                            count ++;
                        }
                    }
                }
            }
        }

        cout << ( count ? "lovely " + to_string(count) : "normal") << endl;


    }

    return 0;
}