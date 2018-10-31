//
// Created by optimus on 7/2/18.
//

# include <iostream>
#include <vector>
# include <iomanip>

using namespace std;

int main(){

    vector<int> denoms = { 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    vector <long long> ways(6001, 1);

    for ( int i = 0; i < denoms.size(); i++){
        for ( int j = denoms[i]; j < ways.size(); j ++){
            ways[j] += ways[j-denoms[i]];
        }
    }

    float abc;

    while ( cin >> abc, abc != 0.0F){
        float abcc = abc * 100;
        cout << fixed << setprecision(2) << setw(6) << abc << setw(17) << ways[abcc/5] << endl;
    }


    return 0;
}