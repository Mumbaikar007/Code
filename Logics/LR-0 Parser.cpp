//
// Created by optimus on 11/4/18.
//

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

struct States {
    vector <int> productions;
    vector <char, States> to;
    //vector <pair <int,int>>  treeLevel;
};

int main(){

    int numberOfProductions;

    cout << "Enter number of productions: " << endl;
    cin >> numberOfProductions;

    vector <string> givenProductions(numberOfProductions + 1);
    givenProductions[0] = "";
    for ( int i = 1 ; i <= numberOfProductions; i ++){
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

    vector <States> allPossibleStates;
    givenProductions[0] = givenProductions[0][0] + "'-" + givenProductions[0][0];
    int currentStateToBeChecked = 0;

    //State Maker
    int statesToBeChecked = 1;
    while ( statesToBeChecked != 0){

        //Current State
        vector <int> productionIndexes;
        vector<char> productionNonTerminals;
        //productionIndexes.push_back();
        productionIndexes.push_back(0);

        for ( int i = 0 ; i < productionIndexes.size(); i ++){

            string currentProductionBeingScanned = givenProductions[productionIndexes[i]];

            int j = ( currentProductionBeingScanned[2] == '-') ? 3 : 2;
            //for ( ; j < currentProductionBeingScanned.size(); j ++){

            // finding if non-terminal
            if ( find(nonTerminals.begin(), nonTerminals.end(), currentProductionBeingScanned[j]) != nonTerminals.end()){

                // check if it's production exists currently
                if ( find ( productionNonTerminals.begin(), productionNonTerminals.end(),
                            currentProductionBeingScanned[i]) != productionNonTerminals.end()){

                    productionNonTerminals.push_back(currentProductionBeingScanned[i]);
                    for ( int k = 0 ; k < givenProductions.size(); k ++){
                        if ( givenProductions[k][0] == currentProductionBeingScanned[i]){
                            productionIndexes.push_back(k);
                        }
                    }

                }
            }
            //}
        }

        sort(begin(productionIndexes), end(productionIndexes));

        int newStateRequired = 1;
        for ( States s: allPossibleStates){
            if (s.productions == productionIndexes){
                newStateRequired = 0;
                break;
            }
        }

        if(newStateRequired){
            States states;
            states.productions = productionIndexes;
            statesToBeChecked ++;
        }

        currentStateToBeChecked ++;
        statesToBeChecked --;

    }



    return 0;
}