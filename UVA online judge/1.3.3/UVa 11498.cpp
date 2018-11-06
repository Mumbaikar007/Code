//
// Created by optimus on 6/11/18.
//

# include <iostream>

using namespace std;

int main() {

    int testcase;
    cin >> testcase;

    int divisionX, divisionY;
    int cityX, cityY;

    /*
     *      while ( cin >> tCases && tCases ){
     *          cin >> divisionX >> divisionY;
     *          while ( tCases -- ){
     *              ...
     *          }
     *      }
     */

    while (testcase != 0){

        cin >> divisionX >> divisionY;

        while ( testcase --){

            cin >> cityX >> cityY;

            if ( cityX == divisionX || cityY == divisionY)
                cout << "divisa";

            else if ( cityX < divisionX ){

                if ( cityY < divisionY)
                    cout << "SO";
                else
                    cout << "NO";
            }

            else {

                if( cityY < divisionY)
                    cout << "SE";
                else
                    cout << "NE";
            }

            cout << endl;
        }

        cin >> testcase;

    }

    return 0;
}