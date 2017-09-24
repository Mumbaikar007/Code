# include <iostream>

using namespace std;

int main(){

	int tests;
	cin >> tests;

	while (tests --){

		long int number;
		cin >> number;

		int first, last = 0;

		first = number % 10;

		while (number != 0){

			last = number % 10;
			number /= 10;

		}

		cout << last + first << endl;

	}


	return 0;
}