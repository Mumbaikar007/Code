
# include <iostream>
# include <climits>
# include <vector>

using namespace std; 

int CutRod (vector <int> price_list, int size){
	
	if (size == 0){
		return 0;
	}
	
	int maxcost = INT_MIN ;

	for ( int i = 1; i <= size ; i ++)
		maxcost = max ( maxcost, price_list[i] +CutRod(price_list, size-i));

	return maxcost;

}


int main(){

	vector<int> price_list = {0,1,5,8,9,10,17,17,20,24,30};

	cout << CutRod(price_list, 3) << endl;

	return 0;
}