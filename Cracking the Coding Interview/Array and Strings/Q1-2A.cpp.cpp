//
// Created by optimus on 4/11/17.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPermute( string s, string t){
    if (s.size() != t.size())
        return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    //cout << s << endl << t << endl;
    return s.compare(t);
}

int main(){

    string str1, str2;
    cin >> str1 >> str2;

    cout << ( !isPermute ( str1, str2) ? "YES" : "NO");

    return 0;
}

