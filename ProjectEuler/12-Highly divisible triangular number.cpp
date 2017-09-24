/*
	Problem:
		https://projecteuler.net/problem=12
	
	References:
		https://www.mathsisfun.com/numbers/factors-all-tool.html
*/

# include <iostream>

using namespace std;

int Factors ( long int sum){
	
	int count_factors = 2;
	int game_changer = sum;
	
	for ( long int i = 2 ; i < game_changer ; i ++){
		if ( sum % i == 0){
			game_changer = sum /  i ;
			count_factors += 2;
		}
	}

	return count_factors;
}


int main(int argc, char const *argv[])
{
	long int sum = 0;

	for ( unsigned int i = 1; i < 100000 ; i ++ ){
		
		sum += i;
		
		int factors = Factors (sum);

		if ( factors > 500){
			cout << sum;
			break;
		}

	}

	return 0;
}
