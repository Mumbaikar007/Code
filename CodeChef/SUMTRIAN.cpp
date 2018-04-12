# include <iostream>
# include <vector>

using namespace std;

int main(){
	
	int tests;
	cin >> tests;

	while (tests--){
		int n;
		cin >> n;
		
		vector< vector < int > > v (n);

		for ( int i = 0 ; i < n ; i ++)
			v[i] 	.resize(n);

		for ( int i = 0 ; i < n ;i ++){
			for ( int j = 0 ; j <= i ; j ++){
				cin >> v[i][j];
			}
		}

		for ( int i = n - 1; i > 0 ; i-- ){
			for ( int j = 0 ; j < i ; j ++ ){
				v[i-1][j] = v[i-1][j] + max( v[i][j], v[i][j+1]);
			}
		}

/*		for ( int i = 0 ; i < n ;i ++){
			for ( int j = 0 ; j <= i ; j ++){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}*/

		cout << v[0][0] << endl;
	}
	return 0;
}