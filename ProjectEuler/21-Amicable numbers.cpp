# include <iostream>
# include <vector>

using namespace std;

int main(){

	vector <int> a (10000) ;
	
	for ( int i = 1; i < 10000 ; i++){
		for ( int j = i*2 ; j< 10000 ; j += i){
			a[j] += i;
		}
	}


	int sum = 0;



	for ( int i = 1; i < 10000 ; i ++){	
		if ( i != a[i] && i == a[a[i]] ){
			sum += i ;
			cout << i << " ";
		}
	}

	cout << sum << endl;

	return 0;
}