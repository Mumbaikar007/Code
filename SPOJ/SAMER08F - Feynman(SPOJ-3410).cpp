/*
	Problem:
		http://www.spoj.com/problems/SAMER08F/
*/

# include <iostream>

using namespace std;

unsigned int SumOfSquares ( int  number){
	
	if ( number == 1)
		return 1;

	return (number * number) + SumOfSquares ( number - 1); 
}

int main(int argc, char const *argv[])
{
	int N ;
	while ( 1 ){
		cin >> N ;
		if ( N == 0)
			break;
		cout << SumOfSquares(N) << endl;
	}
	return 0;
}