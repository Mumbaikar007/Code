#include <iostream>
# include <string>

using namespace std;

int main()
{
    string input_string;
    int count = 0;
    
    cin >> input_string;
    
    for ( int i = 0 ; i < input_string.size(); i ++){
        if ( input_string[i] % 2 == 0)
            count ++;
    }
    
    for ( int i = 0 ; i < input_string.size() ; i ++){
        cout << count << " ";
        if ( input_string[i] % 2 == 0)
            count --;
    }
    
    return 0;
}
