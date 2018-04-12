
# include <iostream>
# include <climits>
# include <vector>

using namespace std;

int MemorizedCutRodAux ( vector <int> price_list, int size, vector <int> record, vector <int> *solutionSet){

	if ( record[size] > 0)
		return record[size];

	if ( size == 0)
		return 0;

	int maxCost = INT_MIN ;

	record[0] = 0;

	for ( int i = 1; i <= size ; i ++){
		
		int temporary = (price_list[i] + MemorizedCutRodAux ( price_list, size - i , record, solutionSet) );
		if ( maxCost < temporary){
			maxCost = temporary;
			(*solutionSet) [size] = i; 
		}
	}

	record [size] = maxCost; 

	return maxCost;

}

int MemorisedCutRod ( vector <int> price_list, int size, vector<int> *solutionSet){
	
	vector <int> record (size);
	
	for ( int i = 0 ; i <= size ; i ++)
		record [i] = INT_MIN;

	return MemorizedCutRodAux ( price_list, size, record, solutionSet);
}



int main(){

	vector <int> price_list = { 0, 1, 5, 8, 9, 10 , 17, 17, 20, 24, 30};

	vector <int> solutionSet  ;
	solutionSet.push_back (0);
	int size = 4;

	solutionSet.resize ( size+1 );

	cout << MemorisedCutRod (price_list, size, &solutionSet) << endl ;

	for ( int i = 1 ; i < solutionSet.size() ; i ++)
		cout << solutionSet[i] << " ";

	cout << endl;
	
	return 0;
}