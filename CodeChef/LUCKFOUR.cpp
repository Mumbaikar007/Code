# include <iostream>

using namespace std;

int main(){

	int tests;
	cin >> tests;

	while (tests --){

		long int N;
		cin >> N;

		int fours = 0;

		while (N != 0){
			if ( (N%10) == 4)
				fours ++;
			N /= 10;
		}

		cout << fours << endl;

	}

	return 0;
}