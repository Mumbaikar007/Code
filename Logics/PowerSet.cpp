# include <iostream>
# include <vector>
# include <cmath>

using namespace std;

void printPowerSet( vector<int> vec){

	int power = pow(2,vec.size()); 
	
	for ( int i = 0; i < power ; i ++){
		for ( int j = 0 ; j < vec.size(); j ++){
			if ( i & (1 << j))
				cout << vec[j];
		}
		cout << endl;
	}


}


int main(int argc, char const *argv[])
{
	vector<int> vec {1,2,3};
	printPowerSet(vec);
	return 0;
}