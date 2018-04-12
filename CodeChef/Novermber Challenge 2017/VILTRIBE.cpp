//
// Created by optimus on 8/11/17.
//

# include <iostream>
# include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){
        string str;
        cin >> str;

        int a = 0, b = 0, count = 0 ;
        int setA = 0, setB = 0;

        for ( int i = 0 ;i < str.size(); i ++){

            if ( str.at(i) == 'A'){
                if (setA)
                    a += count;
                a += 1;
                count = 0;
                setA = 1;
                setB = 0;
            }

            else if ( str.at(i) == 'B'){
                if (setB)
                    b += count;
                b += 1;
                count = 0;
                setB = 1;
                setA = 0;
            }

            else
                count ++;

        }

        cout << a << " " << b << endl ;
    }

    return 0;
}

