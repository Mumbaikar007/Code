# include <iostream>

using namespace std;

int main(){
	int tests;
	cin >> tests;

	while (tests --){
		long int arr[3];
		for ( int i = 0 ; i < 3; i ++){
			cin >> arr[i];
		}

		long int first, second;
		first = second = 0;

		for ( int i = 0 ; i < 3 ; i ++){
			if ( arr[i] > first){
				second = first;
				first = arr[i];
			}

			else if (arr[i] > second){
				second = arr[i];
			}
		}

		cout << second << endl;



	}
	return 0;
}