//
// Created by optimus on 6/11/18.
//

# include <iostream>

using namespace std;

int main(){

    int testCases, currentTestcase = 1;
    cin >> testCases;

    int salary1, salary2, salary3;

    // Storing in vector and sorting was an option.

    while (testCases--){

        cin >> salary1 >> salary2 >> salary3;

        if ( (salary1 > salary2 && salary1 < salary3) ||
                (salary1 > salary3 && salary1 < salary2) )
            cout << "Case " << currentTestcase ++ << ": " << salary1;

        else if ((salary2 > salary1 && salary2 < salary3) ||
                (salary2 > salary3 && salary2 < salary1))
            cout << "Case " << currentTestcase ++ << ": " << salary2;

        else
            cout << "Case " << currentTestcase ++ << ": " << salary3;

        cout << endl;
    }

    return 0;
}