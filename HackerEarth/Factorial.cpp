#include <iostream>
# include <vector>

using namespace std;

long int Factorial (int number, vector <long int> &factorials_array ){
    
    if ( factorials_array [number] == 0 )
        factorials_array[number] = (Factorial (number - 1, factorials_array) * number);
        
    return factorials_array[number]  % ( 1000000007) ;
}


int main()
{
    int tests;
    vector <long int> factorials_array( 100000 );
    
    factorials_array[0] = 1;
    factorials_array[1] = 1;
    cin >> tests;
    
    while ( tests --){
        
        int number;
        cin >> number;
        cout << Factorial (number, factorials_array) << endl;
        
    }
    
    return 0;
}