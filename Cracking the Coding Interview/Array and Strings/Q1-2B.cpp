//
// Created by optimus on 4/11/17.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int isPermute( string s, string t){

    if (s.size() != t.size())
        return false;

    vector<int> vec(256);
    for ( int i =0 ; i < s.size() ; i ++)
        vec[s[i]] ++;

    for ( int i = 0 ; i < t.size() ; i ++){
        vec[t[i]] --;
        if (vec[t[i]] < 0)
            return false;
    }

    return true;
}

int main(){

    string str1, str2;
    cin >> str1 >> str2;

    cout << ( isPermute ( str1, str2) ? "YES" : "NO");

    return 0;
}

