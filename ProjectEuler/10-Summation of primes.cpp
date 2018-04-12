/*
	Problem:
		https://projecteuler.net/problem=10

	References:
		http://www.cplusplus.com/reference/vector/vector/
		https://stackoverflow.com/questions/4236853/floating-point-exception-c-why-and-what-is-it

*/

# include <iostream>
# include <vector> 
# include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	vector <long int> primes;

	primes.push_back(2);
	long int sum = 2 ;

	for ( long int i = 3; i <= 2000000; i++){

		int flag = 1;
		double root = sqrt(i);
		for ( int b = 0 ; primes[b] <= root ; ++b){
			
			if (i % primes[b] == 0){
				flag = 0;
				break;
			}

		}

		if ( flag ){
			primes.push_back(i);
			sum += i;
		}

	}

/*	for ( int i = 0 ; i < primes.size() ; i ++){
		cout << primes[i] << " ";
	}
	*/
	cout << endl << sum;

	return 0;
}