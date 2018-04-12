

# include <iostream>
# include <string>
# include <vector>

using namespace std;

void PrintLCS ( std::vector < std::vector < char > > &direction , string &x, int i , int j){

	if ( i == 0 || j == 0)
		return;

	if ( direction [i][j] == 'D'){
		PrintLCS ( direction, x, i -1 ,j -1);
		cout << x[i] ;
	}

	else if (direction [i][j] == 'U')
		PrintLCS(direction, x, i - 1, j);

	else 
		PrintLCS ( direction, x, i, j-1);

}



int main(){

	string x, y ;

	cin >> x >> y ;

	std::vector < std::vector < int > > cost;
	std::vector < std::vector < char > > direction;

	int x_size = x.size() + 1;
	int y_size = y.size() + 1;

	cost.resize(x_size);
	direction.resize( x_size);

	for ( int i = 0; i < x_size  ; i ++){
		cost[i].resize( y_size );
		direction[i].resize( y_size );
	}



	for ( int i = 0 ; i < x_size ; i ++)
		cost[i][0] = 0;

	for ( int i = 0 ; i < y_size ; i ++)
		cost[0][i] = 0;

	for ( int i = 1 ; i < x_size ; i ++){

		for ( int j = 1 ; j < y_size; j ++){

			if ( x[i] == y[j] ){

				cost [i][j] = cost [i-1][j-1] + 1;
				direction[i][j] = 'D' ;

			}

			else if ( cost [i-1][j] >= cost[i][j-1]){

				cost[i][j] = cost[i-1][j];
				direction[i][j] = 'U' ;

			}

			else {

				cost[i][j] = cost[i-1][j];
				direction[i][j] = 'L' ;

			}

		}

	}


	PrintLCS ( direction, x, x.size(), y.size());


	return 0;
}