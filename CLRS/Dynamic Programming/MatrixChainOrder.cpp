

# include <iostream>
# include <vector>
# include <climits>

using namespace std;

void PrintOptimalParens ( int bracket [100][100], int i, int j){

	if ( i == j ) 
		cout << "A" << i << " ";

	else {
		cout << "( ";
		PrintOptimalParens ( bracket, i , bracket[i][j]);
		PrintOptimalParens ( bracket, bracket[i][j] + 1, j);
		cout << ") ";
	}


}




int main (){

	// Exe 15.2-1
	vector <int> matrixChain = { 5, 10, 3, 12, 5, 50, 6} ;

	int cost[100][100], bracket[100][100] ; 

	int n =  matrixChain.size() - 1;

	for ( int i = 1; i <= n ; i ++)
		cost [i][i] = 0;

	for ( int length = 2; length <= n; length ++){

		int limitForI = (n - length + 1 );
		
		for ( int i = 1 ; i <= limitForI ; i ++ ){

			int j = i + length - 1;

			cost[i][j] = INT_MAX ; 

			int limitForK = j - 1;

			for ( int k = i; k <= limitForK ; k ++){

				int q = cost[i][k] + cost[k+1][j] + ( matrixChain[i-1] * matrixChain[k] * matrixChain[j] );

				if ( q < cost [i][j] ) {

					cost [i][j] = q;

					bracket[i][j] = k;

				}
			}
		}
	}

	PrintOptimalParens ( bracket, 1, n);

	return 0;
} 