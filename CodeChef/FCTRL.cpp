# include <iostream>

using namespace std;

int main(){

	int tests;
	cin >> tests;

	while ( tests-- ){
		long int number;
		cin >> number;

		long int a = 5;
		int zeros = 0;

		while ( (number / a ) != 0 ){

			zeros += (number / a);

			a *= 5;

		}

		cout << zeros << endl;

	}

	return 0;
}