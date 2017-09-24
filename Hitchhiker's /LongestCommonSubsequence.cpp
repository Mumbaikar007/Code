
//Printing only the length
# include <iostream>
# include <string>
# include <vector>

using namespace std;

int main(){

	string x, y ;

	cin >> x >> y ;

	

	for ( int i = 0; i < x_size  ; i ++){
		cost[i].resize( y_size );
	}
w
	for ( int i = 1 ; i < x_size ; i ++){

		for ( int j = 1 ; j < y_size; j ++){

			if ( x[i] == y[j] )
				cost [i][j] = cost [i-1][j-1] + 1;

			else
				cost[i][j] = max (cost[i][j] )
	

		}

	}


	PrintLCS ( direction, x, x.size(), y.size());


	return 0;
}