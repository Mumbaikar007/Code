# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main(){

	int t;
	cin >> t;

	while (t--){

		int n;
		cin >> n;

		vector<int> vec(n);
		for ( int i = 0 ; i < n ; i ++)
			cin >> vec[i];

		
		vector<long> v1 (n);

		for ( int i = 0 ; i < n ; i ++){

			long prefix = 0 , suffix = 0;

			for ( int j = 0 ; j <= i ; j ++)
				prefix += vec[j];

			int st = n - i;
			//cout << st << endl;
			for ( int j = n-st; j < n ; j ++)
				suffix += vec[j];

			v1[i] = suffix + prefix;
			

		}

		for ( int i = 0 ; i < n ; i ++){
			if ( v1[i] == *min_element(v1.begin(), v1.end()) ){
				cout << i + 1;
				break;
			}
		
		}


	}

	return 0;
}
