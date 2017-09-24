# include <iostream>

using namespace std;

int main(){

	int tests;
	cin >> tests;

	while (tests--){

		long int N,M = 0;
		cin >> N;

		while ( N != 0){

			int rem = ( N % 10 );
			M = M * 10 + rem;
			N /= 10;

		}

		cout << M << endl;
	}

	return 0;
}