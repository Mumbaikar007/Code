# include <iostream>

using namespace std;

int c[500010], d[500010], n;

void play(){
	
	int i;
	c[1] = d[1] = 1;
	c[2] = 2; d[2] = 1;

	for ( i = 0 ; i < 500010 ; i ++){
		
		if ( i % 2 ){
			c[i] = d[i/2] * 2;
			d[i] = c[i/2 + 1] * 2 - 1;
		}

		else {
			c[i] = c[i/2] * 2;
			d[i] = d [i/2] * 2 - 1;
		}
	}
}

int main(){
	play();
	while ( cin >> n && n)
		cout << c[n] << endl;
	return 0;
}