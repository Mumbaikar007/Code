# include <iostream>
# include <string>
# include <vector>

using namespace std;

bool isUnique1 (string str){
	
	int char_set = 0;

	for ( int i = 0 ; i < str.size(); i ++){
        int val = str[i] - 'a';
		if ( (char_set & ( 1 << val)) > 0) {
			cout << char_set << endl;
            return false;
		}


		char_set |= (1 << val );

	}

	return true;

}


int main(){

	string str;
	cin >> str;

	cout << (isUnique1(str) ? "YES" : "NO") << endl;

	return 0;
}