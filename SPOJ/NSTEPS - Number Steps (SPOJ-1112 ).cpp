/*
	Problems:
		http://www.spoj.com/problems/NSTEPS/
	References:
*/
# include <iostream>

using namespace std;

void Display(int number, int x, int y){
	switch ( number) {
		case 0: cout << x + y << endl;
				break;
		case 1: cout << x + y - 1 << endl;

	}
}

int main(int argc, char const *argv[])
{
	int tests;
	cin >> tests;

	while (tests--){
		int x, y;
		cin >> x >> y ;

		if ( x == y){
			Display( x % 2, x, y);
		}

		else if ( y == x - 2){
			Display ( x % 2, x, y);
		}

		else {
			cout << "No Number" << endl;
		}
	}

	return 0;
}