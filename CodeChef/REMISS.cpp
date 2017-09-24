# include <iostream>

using namespace std;

int main(){

	int tests;
	cin >> tests;

	while (tests --){
		long int A, B;
		cin >> A >> B;

		cout << (A > B ? A : B) << " " << A + B << endl;

	}

	return 0;
}