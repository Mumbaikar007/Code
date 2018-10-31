# include <iostream>
# include <vector>

using namespace std;

int main(){

	int tests;
	cin >> tests;

	while (tests --){

		int n;
		cin >> n;

		vector <int> array (n);
		int nos[10] = {0};
		int rainbow = 1;
		int up = 1;

		cin >> array[0];
		if (array[0] != 1)
			rainbow = 0;

		for ( int i = 1 ; i < n ; i ++){
			cin >> array[i];
			

			if ( up ){
				nos[array[i]] ++;
				if ( array[i] == array [i-1] || array[i] == (array[i-1] + 1) );
				else if ( array [i] == (array[i-1] - 1))
					up = 0;
				else {
					rainbow = 0;
				}
			}

			else{
				if ( array[i] == array [i-1] || array[i] == (array[i-1] - 1) );
				else {
					rainbow = 0;
				}
			}
		}

		

		for ( int i = 0 ; i <= (n/2) ; i ++){

			if ( array[i] != array [n - i - 1] ){
				rainbow = 0 ;
				break;
			}

			if ( array [i] > 7 || array [n - 1 -i] > 7){
				rainbow = 0; break;
			}

		}

		for ( int i = 0 ; i < 8; i ++){
			if ( array[i] == 0)
				rainbow = 0;
		}

		if (rainbow)
			cout << "yes" << endl;
		else 
			cout << "no" << endl;

	}

	return 0;
}