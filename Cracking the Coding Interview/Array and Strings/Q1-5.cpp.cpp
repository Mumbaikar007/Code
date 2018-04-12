//
// Created by optimus on 10/11/17.
//

# include <iostream>
# include <string>
# include <cmath>

using namespace std;

bool oneEditAway ( string str1, string str2){

    if ( abs(str1.size() - str2.size() ) > 1 )
        return false;

    string small =  (str1.size() < str2.size() ) ? str1 : str2 ;
    string large = str1.size() < str2.size() ? str2 : str1;

    int indexs = 0, indexl = 0;
    bool foundDif = false;

    while ( indexs < small.size() && indexl < large.size() ){

        if ( small.at(indexs) != large.at(indexl)){

            if (foundDif) return false;

            foundDif = true;

            if (small.size() == large.size())
                indexs ++;
        }

        else {
            indexs ++;
        }

        indexl ++;
    }

    return true;

}


int main(){

    string str1, str2;
    cin >> str1 >> str2;

    cout << ( oneEditAway ( str1, str2) ? "YES" : "NO");

    return  0;
}

