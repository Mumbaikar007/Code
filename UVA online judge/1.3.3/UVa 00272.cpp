//
// Created by optimus on 17/1/18.
//

# include <iostream>

using namespace std;

int main(){

    string line;

    int a = 0;

    while ( getline( cin , line )){
        for ( int i = 0 ; i < line.size(); i ++){

            if ( line[i] == '"'){

                if (!a)
                    cout << "``";
                else
                    cout << "''";

                a = !a;

            }
            else
                cout << line[i];
        }
        cout << endl;
    }


    return 0;
}