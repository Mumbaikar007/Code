/*
	Problem:
		http://www.spoj.com/problems/ACPC10A/
	Reference:
		https://codegeeksblog.wordpress.com/2013/06/01/spoj-acpc10a-whats-next/
*/

# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c ;
	
	while ( (a || b || c) ){
		
		if ( c - b == b - a){	
			cout << "AP " << (c + (c-b));
		}
		else{
			cout << "GP " << ( c * (c / b)) ;
		}
		cout << endl;		
		cin >> a >> b >> c;
	}
	return 0;
}