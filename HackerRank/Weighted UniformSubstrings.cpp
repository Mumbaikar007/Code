# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	int n;
	cin >> n;

	vector<int> vec (27);


	for ( int i = 0 ; i < str.size(); ){
		/*if ( find (vec.begin(), vec.end(), str[i]) == vec.end()){
			vec.push_back((int) str[i]);
		}
		else{
			if ( str[i] == str[i-1])
		}*/

		int conticount = 0;
		int j = i;
		while (str[j] == str[i]){
			i ++ ;
			conticount ++;
		}

		//cout << (int)str[j] << "-" << conticount << endl;

		if ( vec[(int)str.at(j) - 96] < conticount )
			vec[(int)str.at(j) - 96] = conticount;
	}

	/*for ( int i = 1; i < 27; i ++)
		cout << vec[i] << " ";*/



	while (n--){

		int z;
		cin >> z;

		int possible = 0;
		for ( int i = 1; i < 27; i++){
			if ( !(z/i) ){
				break;
			}
			if ( (z % i ) == 0){
				if ( (z/i) <= vec[i]){
					possible = 1;
					break;
				}
			}
		}

		cout << ( (possible) ? "YES" : "NO") << endl;

	}
	return 0;
}