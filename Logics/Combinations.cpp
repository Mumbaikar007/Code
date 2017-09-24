# include <iostream>
# include <vector>

using namespace std;

void Combinations (vector <int> vec, int vindex, int index, int r, vector<int> &combi ){
	
	if ( index == r) {
		for ( int i = 0 ; i < r; i ++)
			cout << combi[i] << " ";
		cout << endl;
		return;
	}

	if ( vindex >= vec.size())
		return ;

	combi[index] = vec[vindex];

	Combinations(vec, vindex + 1, index + 1, r, combi);
	
	Combinations(vec, vindex + 1, index, r, combi);

}

int main(int argc, char const *argv[])
{
	int r;
	cin >> r;
	vector <int> vec {1,2,3,4,5}, combi(r);

	Combinations( vec, 0, 0 , r, combi);

	return 0;
}