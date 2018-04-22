//
// Created by optimus on 12/4/18.
//

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector <string> collectionOfFirst, collectionOfFollow;
vector <string> givenProductions;
vector <char> terminals, nonTerminals;

void First ( char nonTerminal, int i ){

    if ( collectionOfFirst[i] == "" ){
        string toAppend = "";
        for ( string s: givenProductions){
            if (s[0] == nonTerminal){
                if ( s[2] <= 'Z'){
                    int j;
                    for ( j = 0 ; j < nonTerminals.size(); j ++){
                        if ( s[2] == nonTerminals[j])
                            break;
                    }
                    First(s[2],j);
                    collectionOfFirst[i] += collectionOfFirst[j];
                }
                else {
                    toAppend += s[2];
                }
            }
        }
        collectionOfFirst[i] += toAppend;
    }

}

int main(){

    int numberOfProductions;
    cout << "Enter number of productions: ";
    cin >> numberOfProductions;

    givenProductions.resize(numberOfProductions);
    cout << "Enter Productions: " << endl;
    for ( int i = 0 ; i < numberOfProductions ; i ++){
        cin >> givenProductions[i];
    }

    for ( string production : givenProductions){
        for ( int i = 0 ; i < production.size(); i ++){

            if (production[i] != '-'){

                if ( production[i] >= 'a' && production[i] <= 'z'){
                    if ( find(terminals.begin(), terminals.end(), production[i]) == terminals.end())
                        terminals.push_back(production[i]);
                }
                else {
                    if ( find(nonTerminals.begin(), nonTerminals.end(), production[i]) == nonTerminals.end())
                        nonTerminals.push_back(production[i]);
                }

            }
        }
    }

    collectionOfFirst.resize(nonTerminals.size(), "" );
    collectionOfFollow.resize(nonTerminals.size(), "");

    for ( int i = 0 ; i < nonTerminals.size(); i ++){
        First(nonTerminals[i], i);
    }

    for (int i = 0; i < nonTerminals.size(); ++i) {
        for (int j = 0; j < givenProductions.size(); ++j) {
            if ( nonTerminals[i] == givenProductions[j][0]){
                string currentProduction = givenProductions[j];
                for ( int k = 2; k < currentProduction.size(); k ++){
                    if ( )
                }
            }
        }
    }

    /*
    int i = 0;
    for ( string s: collectionOfFirst ){
        cout << nonTerminals[i++] << ": ";
        cout << s << endl;
    }
    */



    return 0;
}
