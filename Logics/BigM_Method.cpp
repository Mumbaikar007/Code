//
// Created by optimus on 5/3/18.
//

# include <iostream>
# include <vector>
# include <algorithm>

# define M 100

using namespace std;

int main(){

    int numberOfVariables, numberOfConstraints;

    cout << "Enter number of variables in objective function (minimise)... " << endl;
    cin >> numberOfVariables;

    cout << "Enter number of constraints... " << endl;
    cin >> numberOfConstraints;

    vector <float> objectiveFunction (numberOfVariables);
    vector <char> objectiveFunctionOperators(numberOfVariables-1);

    cout << endl << "For objective function ... " << endl;
    for ( int i = 0; i < numberOfVariables; i ++){
        cout << "Enter coefficient for variable x" << i+1 << ": ";
        cin >> objectiveFunction[i];
        if ( i != numberOfVariables - 1){
            cout << "Enter operator: ";
            cin >> objectiveFunctionOperators[i];
        }
    }

    cout << endl;



    vector < vector<float> > constraintsMatrix ( numberOfConstraints , vector<float> (numberOfVariables + 1));
    vector <vector<char>> operatorsInConstraints (numberOfConstraints, vector <char> (numberOfVariables));

    cout << "For constraints ... " << endl;
    for ( int i = 0; i < numberOfConstraints; i ++){

        for ( int j =0; j < numberOfVariables; j ++){

            cout << "Enter coefficient of variable x" << j+1 << " in constraint " << i+1 << ": ";
            cin >> constraintsMatrix[i][j];

            if ( j != numberOfVariables - 1){
                cout << "Enter operator: ";
                cin >> operatorsInConstraints[i][j];
            }
        }

        cout << "Enter inequality: " ;
        cin >> operatorsInConstraints[i][numberOfVariables-1];

        cout << "Enter RHS: " ;
        cin >> constraintsMatrix[i][numberOfVariables];
        cout << endl;

    }


    cout << "The LPP problem is ... " << endl;
    cout << endl << "Objective Function ... " << endl;
    cout << "Z = ";
    for ( int i = 0; i < numberOfVariables; i ++){
        cout << objectiveFunction[i] << "x" << i+1 << " ";
        if ( i != numberOfVariables - 1){
            cout << objectiveFunctionOperators[i] << " ";
        }
    }

    cout << endl;

    cout << "Subject to ..." << endl;
    for ( int i = 0; i < numberOfConstraints; i ++){

        for ( int j =0; j < numberOfVariables; j ++){

            cout << constraintsMatrix[i][j] << "x" << j+1 << " ";

            if ( j != numberOfVariables - 1){
                cout << operatorsInConstraints[i][j] << " ";
            }
        }

        if ( operatorsInConstraints[i][numberOfVariables-1] == '=')
            cout << "=";
        else
            cout << operatorsInConstraints[i][numberOfVariables-1] << "=";

        cout << " " << constraintsMatrix[i][numberOfVariables] << endl;
    }


    int slackVariables = 0 , artificialVariables = 0;
    vector < vector<int> > slacks(numberOfConstraints, vector<int> (2));
    for ( int i = 0 ; i < numberOfConstraints ; i ++){
        if ( operatorsInConstraints[i][numberOfVariables-1] == '='){
            slacks[i][0] = 0;
            slacks[i][1] = 1;
            artificialVariables ++;
        }
        else if ( operatorsInConstraints[i][numberOfVariables-1] == '>' ){
            slacks[i][0] = -1;
            slacks[i][1] = 1;
            slackVariables++;
            artificialVariables++;
        }
        else {
            slacks[i][0]= 1;
            slacks[i][1] = 0;
            slackVariables++;
        }
    }

    cout << "Standard LPP Problem ..." << endl;
    cout << endl << "Objective Function ... " << endl;
    cout << "Z = ";

    for ( int i = 0; i < numberOfVariables; i ++){
        cout << objectiveFunction[i] << "x" << i+1 << " ";
        if ( i != numberOfVariables - 1){
            cout << objectiveFunctionOperators[i] << " ";
        }
    }

    int columns = 0, rows = 0;
    for (int i = 0; i < numberOfConstraints; i++) {

        if (slacks[i][0]) {
            cout << "+ 0s" << i + 1 << " ";
            columns ++;
        }

    }
    for (int i = 0; i < numberOfConstraints; i++) {
        if (slacks[i][1]) {
            cout << "+ MA" << i + 1 << " ";
            columns ++;
            rows ++;
        }
    }

    cout << endl;


    cout << "Subject to ..." << endl;
    for ( int i = 0; i < numberOfConstraints; i ++){

        for ( int j =0; j < numberOfVariables; j ++){

            cout << constraintsMatrix[i][j] << "x" << j+1 << " ";

            if ( j != numberOfVariables - 1){
                cout << operatorsInConstraints[i][j] << " ";
            }
        }

        if ( slacks[i][0] ){
            cout << ( slacks[i][1] ? "- s" : "+ s") << i + 1 << " ";
        }

        if ( slacks[i][1] )
            cout << "+ A" << i+1 << " ";

        cout << " = " << constraintsMatrix[i][numberOfVariables] << endl;
    }

    columns += numberOfVariables;
    columns += 1; // RHS

    vector < vector<float> > theBigTable ( rows, vector<float> (columns));

    for ( int i = 0 ; i < rows; i ++){

        for ( int j = 0 ; j < numberOfVariables ; j ++){
            theBigTable[i][j] = constraintsMatrix[i][j];
        }

        theBigTable[i][numberOfVariables + i] = slacks[i][0];
        theBigTable[i][numberOfVariables + i + numberOfConstraints] = slacks[i][1];
        theBigTable[i][columns-1] = constraintsMatrix[i][numberOfVariables]; // RHS
    }

    vector <float> cj (columns -1), bigTableCoefficient(rows);
    for ( int i = 0 ; i < numberOfVariables; i ++)
        cj[i] = objectiveFunction[i];

    for ( int i = 0 ; i < artificialVariables ; i ++){
        cj[i+numberOfVariables+slackVariables] = M;
    }

    for ( int i = 0 ; i < rows ; i ++){
        bigTableCoefficient [i] = M;
    }

    cout << endl << "the big table ..." << endl;

    for ( int i = 0 ; i < columns -1; i ++ )
        cout << cj[i] << " ";
    cout << endl;
    for ( int i = 0 ; i < rows; i ++){
        cout << bigTableCoefficient[i] << " ";
        for ( int j = 0 ; j < columns ; j ++){
            cout << theBigTable[i][j] << " ";
        }
        cout << endl;
    }

    int allZeroAndMore = 1;

    vector<int> variablesInAnswer (rows);
    //int I = 3;
    while ( allZeroAndMore){

        float minimumColumnValue = 1000, minimumColumnPosition =-1;
        float minimumRowValue = 1000, minimumRowPosition =-1;
        vector<float> cjzj(columns);
        allZeroAndMore = 0;

        for ( float i = 0; i < columns; i ++){

            // Selecting a column
            for ( int j = 0 ; j < rows; j ++){
                cjzj [i] += ( theBigTable[j][i] * bigTableCoefficient[j] ) ;
            }

            if ( i != columns -1)
                cjzj[i] = cj[i] - cjzj[i];

            allZeroAndMore = ( cjzj[i] < 0 ) ? 1: allZeroAndMore;

            if ( minimumColumnValue > cjzj[i] ){
                minimumColumnValue = cjzj[i];
                minimumColumnPosition = i;
            }
        }

        /*
        cout << "cjzj " << endl ;
        for ( int i = 0 ; i < columns; i ++)
            cout << cjzj[i] << " ";
        cout << endl;
        */

        if ( !allZeroAndMore) break;

        //Selecting a row
        for ( int j = 0 ; j < rows; j ++ ){

            float abc = theBigTable[j][columns-1] / theBigTable[j][minimumColumnPosition] ;
            //cout << abc << endl;
            if ( minimumRowValue > abc){
                minimumRowValue = abc;
                minimumRowPosition = j;
            }
        }

        // cout << endl << minimumRowPosition << " " << minimumColumnPosition << endl;
        variablesInAnswer[(int)minimumRowPosition] = (int)minimumColumnPosition;

        float keyElement = theBigTable[minimumRowPosition][minimumColumnPosition];

        for ( int i = 0 ; i < columns ; i ++ ){
            theBigTable[minimumRowPosition][i] /= keyElement;
        }

        for ( int i = 0 ; i < rows; i ++){
            if ( i != minimumRowPosition ){
                float theColumnValue = theBigTable[i][minimumColumnPosition];
                for ( int j = 0; j < columns; j ++){
                    theBigTable[i][j] = theBigTable[i][j] - theColumnValue * theBigTable[minimumRowPosition][j];
                }
            }
        }

        int someColumn = numberOfVariables + slackVariables + minimumRowPosition;
        for ( int i = 0 ; i < rows; i ++){
            theBigTable[i][someColumn] = 0;
        }

        bigTableCoefficient [minimumRowPosition] = cj[minimumColumnPosition];

        cout << endl << "the big table ..." << endl;

        for ( int i = 0 ; i < columns -1; i ++ )
            cout << cj[i] << " ";
        cout << endl;
        for ( int i = 0 ; i < rows; i ++){
            //cout << bigTableCoefficient[i] << " ";
            for ( int j = 0 ; j < columns ; j ++){
                cout << theBigTable[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Final Z: " ;
    float Z = 0;
    for ( int i = 0 ; i < rows ; i ++){
        Z += ( theBigTable[i][columns-1] * bigTableCoefficient[i]);
    }
    cout << Z << endl;

    cout << "The variables... " << endl;
    for ( int i = 0 ; i < numberOfVariables; i ++){

        auto it = find ( begin(variablesInAnswer), end(variablesInAnswer), i);
        if ( it != end(variablesInAnswer)){
            cout << "x" << i << ": " << theBigTable[it-begin(variablesInAnswer)][columns-1] << endl;
        }
        else{
            cout << "x" << i << ": " << 0 << endl;
        }
    }

    return 0;
}