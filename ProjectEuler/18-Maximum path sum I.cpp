

# include <iostream>
# include <cmath>
# include <vector>


using namespace std;

int main()
{
	int a[16385] ;

	int k = 1 ;

	while ( k <= 120){
		cin >> a[k] ;
		k++;
	}

	cout << endl << "Done" << endl;
/*
	while ( k--){
		cout << a[k] << " ";
	}
	cout << endl;
*/
	
	vector <int> starts;

	int c = 0;

	for ( int i = 1 ; i < 16 ; i ++){
		starts.push_back(c+1);
		for ( int j = 0; j < i ; j ++)
			c++;
	}

	for ( int i = 0 ; i < starts.size() ; i ++)
		cout << starts[i] << " ";

	cout << endl;

	for ( int d = 14 ; d > 0 ; --d){
		
		int i =  starts[d-1];
		int j =  starts[d];

		cout << d << " " << i << " " << j << endl;

		int count = 1;

		while ( count <= d){

			a[i] += max ( a[j], a[j + 1] );
			i ++; j ++;
			count ++;
		} 	
	}
/*
	while ( k--){
		cout << a[k] << " ";
	}
	cout << endl;
*/
	cout << a[1] << endl;

	return 0; 
}	