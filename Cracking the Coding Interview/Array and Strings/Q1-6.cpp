//
// Created by optimus on 10/11/17.
//

# include <iostream>
# include <string>


using namespace std;

string Compressed( string str ){

    int count = 1;
    char rightNow = str.at(0);

    string str2 = "";


    for ( int i = 1; i < str.size() ; i ++){

        if ( str.at(i) == rightNow )
            count ++;

        else {

            str2 += rightNow;
            str2 += to_string(count);


            rightNow = str.at(i);
            count = 1;

        }

    }

    return ( str2.size() > str.size() ) ? str : str2;

}


int main(){

    string str;
    cin >> str;

    cout << Compressed(str) << endl;

    return 0;
}

