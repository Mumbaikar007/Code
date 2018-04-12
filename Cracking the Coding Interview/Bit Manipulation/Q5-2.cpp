
# include <iostream>

using namespace std;

int main(){

	double d ;
	cin >> d;

	string s = "0.";

	if ( d >= 1 || d <= 0){
		cout << "Error";
	}

	else {

		double fract = 0.5;
		while ( d > 0 ){

			if ( s.size() > 32){
				cout << "Error";
				break;
			}

			if ( d >= fract){
				s += "1";
				d -= fract;
			}

			else 
				s += "0";

			fract /= 2;

		}

		cout << s;
	}


	

	return 0;
}