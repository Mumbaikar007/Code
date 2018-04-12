# include <iostream>
# include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> vec(100);
	int a;

	while (n--){
		cin >> a;
		vec[a] ++;
	}

	int max = 0, nos = 0;

	for ( int i = 1 ; i < 99 ; i ++){
		int j = 0;
		if ( vec [i] == 1 && vec[i+1] == 1)
			j = 1;
		else if ( vec[i] > 1 && vec[i+1] > 1)
			j = 3;
		else if ( (vec[i] == 1 && vec[i+1] > 1) || (vec[i] > 1 && vec[i+1] == 1) )
			j = 2;
		if ( max <= j){
			if ( nos < (vec[i] + vec[i+1]))
				nos = vec[i] + vec[i+1];
		}

	}

	cout << nos << endl;

	return 0;
}