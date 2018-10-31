//
// Created by optimus on 5/11/17.
//
# include <iostream>
# include <string>
#include <vector>
# include <iterator>

using namespace std;

bool isPermutationPallindrome( string str ){

    vector <int> freq (26);
    for ( string::iterator it = str.begin(); it != str.end(); it++){
        freq[*it - 'a'] ++;
    }

    int odds = 0;
    for ( int i = 0 ; i < 26 ; i ++){
        if ( freq[i] % 2 != 0)
            odds ++;
    }

    if ( odds > 1)
        return false;
    else if (str.size() % 2 == 0 && odds)
        return false;
    else
        return true;

}

int main() {

    string str;
    cin >> str;

    cout << (isPermutationPallindrome(str) ? "YES" : "NO") << endl;

    return 0;
}