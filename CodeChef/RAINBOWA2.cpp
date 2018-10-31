# include <iostream>
# include <vector>


using namespace std;

int check_palindrome (vector <int> s) {
   int i,j;
   for (i=0,j=s.size()-1 ; i<j ; ++i, --j) {
      if (s[i] != s[j]) return 0; // Not palindrome
   }
   return 1; //Palindrome
}

int main(){

	int tests;
	cin >> tests;

	while (tests--){

		int number;
		cin >> number;

		vector<int> vec (number);
		int array[11] = {0};

		for ( int i = 0 ; i < number ; i ++){
			cin >> vec[i] ;
			array[vec[i]] ++;
		}

		int ans = (check_palindrome (vec) ) ;

		for ( int i = 0 ; i <= 7; i++ ){
			if ( !array [i] )
				ans = 0;

		}

		for ( int i = 8; i <= 10; i ++){
			if ( array[i] )
				ans = 0;
		}

		cout << ( ans ? "yes" : "no" ) << endl;

	}

	return 0;
}