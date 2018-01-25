//
// Created by optimus on 19/1/18.
//

# include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t -- ){

        string s;
        cin >> s;

        if ( s == "1" || s == "4" || s == "78")
            cout << "+" << endl;
        else if ( s.at(s.size()-1) == '5' && s.at(s.size()-2) == '3' )
            cout << "-" << endl;
        else if ( s.at(0) == '1' && s.at(1) == '9' && s.at(2) == '0')
            cout << "?" << endl;
        else if ( s.at(0) == '9' && s.at(s.size()-1) == '4')
            cout << "*" << endl;
        else
            cout << "+" << endl;

    }

    return 0;
}