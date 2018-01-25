//
// Created by optimus on 20/1/18.
//

# include <iostream>
# include <map>
# include <vector>

using namespace std;

int main(){


    int n;
    cin >> n;


    while ( 1 ) {

        map<string, int> M;
        //map<string, int> M;
        vector <string> vec (n);

        for ( int i = 0 ; i < n ; i ++){
            cin >> vec[i];
            M.insert(make_pair(vec[i], 0));
        }


        //cout << "Here as well" << endl;
        string doner, receiver;
        int amount, numberOfReceiver;
        for ( int i = 0 ; i < n ; i ++){

            cin >> doner >> amount >> numberOfReceiver;

            //auto it = m.find(doner);

            //M.find(doner)

            int gifted = amount / numberOfReceiver;

            if ( numberOfReceiver )
                M[doner] -= gifted * numberOfReceiver;

            for ( int j = 0; j < numberOfReceiver; j ++){
                cin >> receiver;
                M[receiver] += gifted ;
            }
            //cout << "next" << endl;
            //for ( int i = 0 ; i < n ; i ++)
              //cout << vec[i] << " " << M[vec[i]] << endl;
        }

        //cout << "Here" << endl;

        for ( int i = 0 ; i < n ; i ++)
            cout << vec[i] << " " << M[vec[i]] << endl;


        if ( cin >> n ) cout << endl;
        else break;
    }

    return 0;
}