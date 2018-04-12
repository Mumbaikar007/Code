//
// Created by optimus on 10/11/17.
//

# include <iostream>
# include <string>

using namespace std;

int main(){

    string str1, str2;
    cin >> str1 >> str2;

    string str = str1 + str1;

    size_t found = str.find(str2);

    cout << ( (found) != string::npos ? "Yes" : "No") << endl;

    return 0;
}