/*
	Problem:
		http://www.spoj.com/problems/ADDREV/
*/

# include <iostream>

using namespace std;

int Reverse ( int number ){

	int reverse = 0;
	while (number){
		int remains = number % 10 ;
		reverse = (reverse * 10) + remains;
		number /= 10;
	}
	return reverse;

}

int main(){

	int tests;
	cin >> tests;

	while (tests --){

		int num1, num2;
		cin >> num1 >> num2;

		num1 = Reverse(num1);
		
		num2 = Reverse(num2);

		int sum = num1 + num2;

		sum = Reverse(sum);

		cout << sum << endl;

	}

	return 0;
}
