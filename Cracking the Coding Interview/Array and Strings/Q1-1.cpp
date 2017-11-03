# include <iostream>
# include <string>
# include <vector>

using namespace std;

bool isUnique (string str){
	
	if ( str.size() > 128)
		return false;

	std::vector<bool> char_set (128);

	for ( int i = 0 ; i < str.size(); i ++){
		
		if ( char_set[str.at(i)] )
			return false;

		char_set[str.at(i)] = true;

	}

	return true;

}


int main(){

	string str;
	cin >> str;

	cout << isUnique(str) << endl;

	return 0;
}