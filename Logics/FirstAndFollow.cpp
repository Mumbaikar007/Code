//
// Created by optimus on 12/4/18.
//

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector <string> collectionOfFirst, collectionOfFollow;

void First ( char nonTerminal ){

}

int main(){

    int numberOfProductions;
    cout << "Enter number of productions: ";
    cin >> numberOfProductions;

    vector <string> givenProductions;
    cout << "Enter Productions: " << endl;
    for ( int i = 0 ; i < numberOfProductions ; i ++){
        cin >> givenProductions[i];
    }

    vector <char> terminals, nonTerminals;
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

    return 0;
}
