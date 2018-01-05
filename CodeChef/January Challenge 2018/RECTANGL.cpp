//
// Created by optimus on 5/1/18.
//

# include <iostream>

using namespace std;

int main(){

    int a, b, c, d, t;
    cin >> t;
    while ( t -- ){

        cin >> a >> b >> c >> d;

        if (    (a == b && c == d ) ||
                (a == c && b == d ) ||
                (a == d && c == b ) )

            cout << "YES" << endl;
        else{
            //cout << a << " " << b << " " << c << " " << d << endl;
            cout << "NO" << endl;
        }


    }

    return 0;
}