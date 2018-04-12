//
// Created by optimus on 1/2/18.
//


# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
#include <sstream>


using namespace std;


int main() {

    string line ;
    char ffname[20];



    cout << "Enter file name: ";
    cin >> ffname;


    ifstream reader;
    reader.open(ffname);


    if ( !reader ){
        cout << "Error opening input file ...";
        return -1;
    }

    cout << "File has the following content ... \n";
    while ( !reader.eof() ){
        getline ( reader, line);
        cout << line << endl;
    }

    cout << "Pass 1: " << endl;

    cout << endl;



    return 0;
}