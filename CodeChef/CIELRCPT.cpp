# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[12] =  { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

	int tests;
	cin >> tests;

	while (tests --){

		int p ;
		cin >> p;

		int i = 11;

		int iters = 0;

		while ( p != 0 ){
			while ( arr[i] > p )
				i--;
			p -= arr[i];

			iters ++;
		}

		cout << iters << endl;

	}

	return 0;
}