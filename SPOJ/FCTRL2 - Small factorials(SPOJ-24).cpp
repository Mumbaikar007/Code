/*
	Problems:
		http://www.spoj.com/problems/classical/sort=6

	References:
		
*/

# include <iostream>

using namespace std;


void Multiply(int *arr, int *size, int number){
	
	int carry = 0, i = 1;

	//cout << arr[i] << endl;

	for ( ; i <= *size ; i ++){
		int product = (arr[i] * number) + carry;
		//cout << i << " Product " << product<< endl;
		arr[i] = (product % 10);
		carry = product / 10;
		//cout << i << " Product " << product<< endl;
	}



	while (carry){
		arr[i++] = carry % 10;
		carry /= 10;
		++ (*size); 
	}
}


void Factorial(int *arr, int *size, int number){

	while ( number){
		Multiply( arr, size, number);
		number --;
	}
	
}



int main(int argc, char const *argv[])
{
	
	int tests;
	cin >> tests ;

	while (tests --){
		
		int number ;
		cin >> number;

		int arr[180];
		arr[1] = 1;
		int size = 1;

		Factorial(arr, &size, number );

		//cout << size << endl;
		for ( int i = size ; i >= 1 ; --i){
			cout << arr[i] ; 
		}
		cout << endl;

	}

	return 0;
}