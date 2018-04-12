# include <iostream>
# include <cmath>

using namespace std;

int main(){
	int rounds;
	cin >> rounds ;

	int p1, p2, max = 0;
 	long int tp1 = 0, tp2 = 0;

	while ( rounds --){
		cin >> p1 >> p2;
		
		tp1 += p1;
		tp2 += p2;
		
		max = (abs (max) < abs(tp1-tp2)) ? (tp1 - tp2) : max;
	}

	cout << ((max < 0) ? 2 : 1);
	cout << " " << abs (max) << endl;
	return 0;
}