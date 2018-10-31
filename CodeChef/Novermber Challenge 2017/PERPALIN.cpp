//
// Created by optimus on 8/11/17.
//

# include <string>
#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t --){

        int n, p;
        cin >> n >> p;

        if ( p <= 2 )
            cout << "impossible" << endl;

        else {

            string op = "";

            if ( p % 2 ){

                string pal = "";
                for ( int i = 0 ; i < p ; i ++)
                    pal+= 'a';
                pal[p/2] = 'b';

                int d = n/p;
                for ( int i = 0 ; i < d ; i ++)
                    op += pal;
            }

            else {
                string pal = "";
                for ( int i = 0 ; i < p ; i ++)
                    pal+= "a";
                pal[p/2] = 'b';
                pal[(p/2) - 1] = 'b';
                int d = n/p;
                for ( int i = 0 ; i < d ; i ++)
                    op += pal;

            }

            cout << op << endl;
        }

    }

    return 0;
}

