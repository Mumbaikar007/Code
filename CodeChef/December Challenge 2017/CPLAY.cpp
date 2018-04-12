//
// Created by optimus on 11/12/17.
//

# include <iostream>

using namespace std;

int main(){

    string string1;

    while (getline(cin,string1)){

        cout << string1 << endl;

        int even = 0 , odd = 0;
        int flag = 0, i;
        for ( i = 0; i < 10; i ++){

            if ( i % 2){

                if ( string1.at(i) == '1')
                    odd ++;
            }

            else {
                if ( string1.at(i) == '1')
                    even ++;
            }

            if ( abs(even-odd) == 4){
                flag = 1;
                break;
            }

        }

        if ( flag ){
            cout << ( ( even > odd) ? "TEAM-A " : "TEAM-B " ) << i << endl;
        }

        else{
            for ( ; i < 20 ; i += 2){
                if ( !abs(string1.at(i)-string1.at(i+1)) )
                    break;
            }
            if (i == 20)
                cout << "TIE" << endl
        }

    }


    return 0;
}