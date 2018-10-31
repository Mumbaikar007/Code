//
// Created by optimus on 11/4/18.
//

# include <iostream>
# include <vector>
# include <algorithm>
#include <iomanip>
# include <string>

using namespace std;

struct States {
	//int productions[100];
    vector <int> productions; //unnecessary
    vector <pair<int, int>> startOfProduction;
    vector <pair<char, int>> toNextState;
    //vector <pair <int,int>>  treeLevel;
};



int main(){

    int numberOfProductions;

    cout << "Enter number of productions: " << endl;
    cin >> numberOfProductions;

    vector <string> givenProductions(numberOfProductions + 1);
    givenProductions[0] = "";
    cout << "Enter Productions... " << endl;
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
    givenProductions[0] =  "Z-" + givenProductions[1].substr(0,1);
    //cout << givenProductions[0]  << endl;
    int currentStateToBeChecked = 0;



    // Making first state

    //Current State
    vector <int> productionIndexes;
    vector <char> productionNonTerminals;
    vector <pair<int, int>> startingProduction;
    //productionIndexes.push_back();
    productionIndexes.push_back(0);

    for ( int i = 0 ; i < productionIndexes.size(); i ++){

        string currentProductionBeingScanned = givenProductions[productionIndexes[i]];

        int j = 2;

        // finding if non-terminal
        if ( find(nonTerminals.begin(), nonTerminals.end(), currentProductionBeingScanned[j]) != nonTerminals.end()){

            // check if it's production exists
            if ( find ( productionNonTerminals.begin(), productionNonTerminals.end(),
                        currentProductionBeingScanned[j]) == productionNonTerminals.end()){
                //cout << "Here" << endl;
                productionNonTerminals.push_back(currentProductionBeingScanned[j]);
                for ( int k = 0 ; k < givenProductions.size(); k ++){
                    if ( givenProductions[k][0] == currentProductionBeingScanned[j]){
                        productionIndexes.push_back(k);
                    }
                }

            }
        }
        //}
    }

    sort(begin(productionIndexes), end(productionIndexes));
    for ( int i: productionIndexes ){
        startingProduction.push_back(make_pair(i, 2));
    }
    States states;
    states.productions = productionIndexes;
    states.startOfProduction = startingProduction;
    allPossibleStates.push_back(states);

    //State Maker
    //int statesToBeChecked = 1;
    while ( currentStateToBeChecked < allPossibleStates.size()){

        vector <char> jumpsMadeUsing;

        // Check symbol (complexity can be easily reduced)
        States states1 = allPossibleStates[currentStateToBeChecked];
        for ( int a = 0 ; a < states1.startOfProduction.size(); a ++){


            if ( find(jumpsMadeUsing.begin(), jumpsMadeUsing.end(),
                      givenProductions[states1.startOfProduction[a].first][states1.startOfProduction[a].second]) == jumpsMadeUsing.end()){

                jumpsMadeUsing.push_back(givenProductions[states1.startOfProduction[a].first][states1.startOfProduction[a].second]);


                // Add productions to new state
                vector <int> productionIndexes2, productionIndexesAddingProductions;
                vector <pair<int, int>> startingProduction2;
                vector <char> productionNonTerminals2;

                for ( int b = a; b < states1.productions.size(); b ++){
                    if ( givenProductions[states1.productions[b]][states1.startOfProduction[b].second]
                            == givenProductions[states1.productions[a]][states1.startOfProduction[a].second]){
                        productionIndexes2.push_back(states1.productions[b]);
                        startingProduction2.push_back(make_pair(states1.startOfProduction[b].first,
                                                                states1.startOfProduction[b].second+1));
                    }
                }

                // Complete making the state
                for ( int i = 0 ; i < startingProduction2.size(); i ++){

                    string currentProductionBeingScanned = givenProductions[startingProduction2[i].first];


                    int j = startingProduction2[i].second;

                    if ( j < currentProductionBeingScanned.size()){
                        // finding if non-terminal
                        if ( find(nonTerminals.begin(), nonTerminals.end(),
                                  currentProductionBeingScanned[j]) != nonTerminals.end()){

                            // check if it's production exists
                            if ( find ( productionNonTerminals2.begin(), productionNonTerminals2.end(),
                                        currentProductionBeingScanned[j]) == productionNonTerminals2.end()){
                                //cout << "Here" << endl;
                                productionNonTerminals2.push_back(currentProductionBeingScanned[j]);
                                for ( int k = 0 ; k < givenProductions.size(); k ++){
                                    if ( givenProductions[k][0] == currentProductionBeingScanned[j]){
                                        productionIndexes2.push_back(k);
                                        startingProduction2.push_back(make_pair(k, 2));
                                    }
                                }

                            }
                        }
                    }
                }


                sort(begin(productionIndexes2), end(productionIndexes2));
                sort(begin(startingProduction2), end(startingProduction2),
                     [](const pair<int, int> &a, const pair<int, int> &b) {
                         return a.first < b.first;
                });


                // Check if State exists and link accordingly
                int newState = 1;
                int zz = 0;
                for ( States states2: allPossibleStates){
                    if ( states2.productions == productionIndexes2){
                        allPossibleStates[currentStateToBeChecked].toNextState.push_back(make_pair(
                        givenProductions[states1.startOfProduction[a].first][states1.startOfProduction[a].second],
                        zz));
                        newState = 0;
                        break;
                    }
                    zz++;
                }
                if ( newState ){

                    States states;
                    states.productions = productionIndexes2;
                    states.startOfProduction = startingProduction2;
                    allPossibleStates.push_back(states);
                    allPossibleStates[currentStateToBeChecked].toNextState.push_back(make_pair(
                            givenProductions[states1.startOfProduction[a].first][states1.startOfProduction[a].second],
                            allPossibleStates.size()-1));

                }

            }

        }

        //Increase State counter
        currentStateToBeChecked ++;
    }

    // Charting
    sort(begin(terminals), end(terminals));
    sort(begin(nonTerminals), end(nonTerminals));
    int cols = terminals.size() + nonTerminals.size() + 1;

    vector <vector<string>> chart ( allPossibleStates.size(),
                                    vector<string> (cols, "-"));

    cout << setw(7) << "States";
    for ( int i = 0 ; i < terminals.size(); i ++){
        cout << setw(7) << terminals[i];
    }
    cout << setw(7) << "$";
    for ( int i = 0 ; i < nonTerminals.size(); i ++){
        cout << setw(7) << nonTerminals[i];
    }
    cout << endl;
    for (int i = 0; i < allPossibleStates.size(); ++i) {
        if ( i == 1){
            chart [i][terminals.size()] = "Accept";
        }
        
            States states1 = allPossibleStates[i];
            if ( states1.productions.size() == 1 && states1.toNextState[0].second == i){
                for ( int k = 0 ; k <= terminals.size(); k ++){
                    chart[i][k] = "r" + to_string(states1.productions[0]);
                }
            }
            else {
                for (int j = 0; j < states1.toNextState.size(); ++j){

                    if ( states1.toNextState[j].first <= 'Z'){
                        auto it = find ( begin(nonTerminals), end(nonTerminals), states1.toNextState[j].first );
                        int position = it - begin(nonTerminals);
                        chart[i][terminals.size()+position+ 1] = to_string(states1.toNextState[j].second);
                    }
                    else {
                        auto it = find ( begin(terminals), end(terminals), states1.toNextState[j].first );
                        int position = it - begin(terminals);
                        chart [i][position] = "S" + to_string(states1.toNextState[j].second);
                    }

                }
            }
       
    }

    for ( int i = 0 ; i < allPossibleStates.size(); i ++){
        cout << setw(7) << "I" << i;
        for ( int j = 0 ; j < cols; j ++){
            cout << setw(7) << chart[i][j];
        }
        cout << endl;
    }

    return 0;
}
