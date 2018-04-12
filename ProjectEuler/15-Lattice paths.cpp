/*
	Problem:
		https://projecteuler.net/problem=15

	References:
		https://blog.dreamshire.com/project-euler-15-solution/
		http://www.mathblog.dk/project-euler-15/
*/

# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	

	long int matrix[21][21];

	for ( int i = 1 ; i <= 20 ; i++ ){
		matrix[i][20] = matrix [20][i] = (long int )(22-i) ;
	}

	for ( int i = 19 ; i >= 0; --i ){
		for ( int j = 19 ; j >= 0 ; --j){
			matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
		}
	}

	cout << matrix[1][1] << endl;


	return 0;
}