/*# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int global = 0;

void sgp ( vector <int> &v, int level, int lastLevel){

	if ( lastLevel == level ){
		int flag = 1;
		for ( int i = 1; i < v.size(); i ++ ){
			if (v[i] == i){
				flag = 0;
				break;
			} 
		}

		if ( flag){
			global = 1;
			return;
		}

	}

	for ( int i = level; i <= lastLevel && !global ; i++){
		iter_swap (v.begin() + level, v.begin() + i);
		sgp (v, level + 1, lastLevel);
		iter_swap (v.begin() + level, v.begin() + i);
	}



}

int main(){

	
	int t;
	cin >> t;

	while (t--){

		int n;
		cin >> n;

		vector<int> v (n + 1);

		for ( int i = 1; i <= n ; i ++)
			v[i] = i;

		sgp ( v, 1, v.size() );

		for ( int i = 1; i < v.size() ; i ++)
			cout << v[i] << " ";

		cout << endl;
		cout << global << endl;

	}





	return 0;
}*/

# include <iostream>
# include <string>
# include <typeinfo>

using namespace std;

string def = "123456789";
int found = 0;

void printPermutations ( string &str, int level, int lastLevel){

	if ( level == lastLevel){
		int good = 1;
		for ( int i = 0 ; i < str.size(); i ++){
			if ( str[i] == def[i] ){
				good = 0;
				break;
			}
		}
		if (good){
			cout << str << endl ;
			found = 1;
			return ;
		}
	}


	for ( int i = level; i <= lastLevel && !found; i ++){

		swap( str[level], str[i] );
		printPermutations (str, level + 1, lastLevel);
		swap( str[level], str[i]);

	}


}


int main(){

	int t;
	cin >> t;

	while (t--){
		
		int n;
		cin >> n;

		string str = def.substr (0,n);
		
		printPermutations ( str, 0, str.size()- 1);

		found = 0;
	}

	return 0;
}