#include<bits/stdc++.h>

using namespace std;

int calculate (string N) {
   
    int ways = 0;
	
	string left, right;
	
    left = N.substr( 0 , N.size() - 1 );
    right = N.substr( N.size() - 1, N.size() );

    int j = 1;
    while ( left != ""){

        //cout << left << " " << right << endl;

        int i;
        for ( i = left.size()-1 ; i >= 0 ; i --){
            if (left.at(i) != '0')
                break;
        }

        if ( i != left.size() ){
                
            long int a = left.size() - i;

            for ( long int x = 0 ; x <= a ; x ++){
                string cmp = to_string(x);

                if ( cmp == right ){
                    ways ++;
                }
            }
        }

        int k;
        for ( k = right.size()-1 ; k >= 0 ; k --){
            if (right.at(k) != '0')
                break;
        }        

        if ( k != right.size() ){
            
            long int a = right.size() - k;

            for ( long int x = 0 ; x <= a ; x ++){
                string cmp = to_string(x);

                if ( cmp == left ){
                    ways ++;
                }
            }

        }

        j++;
        left = N.substr(0, N.size()-j);      
        right = N.substr(N.size()-j, N.size());
    }

    return ways;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string N;
    getline(cin, N);

    int out_;
    out_ = calculate(N);
    cout << out_ << endl;
}