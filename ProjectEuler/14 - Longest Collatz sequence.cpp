/*
	Problem:
		https://projecteuler.net/problem=14
*/

# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned int number = 1000000;

	unsigned int answer = 100000;
	int answer_count = 0;

	while (number > 100000){
		
		unsigned int a = number;
		int count = 0 ;

		while (a != 1){
			if ( a % 2 == 0){
				a = a / 2;
			}
			else 
				a = 3 * a + 1;
			count ++;
		}

		if ( answer_count < count){
			answer_count = count;
			answer = number;
		}

		-- number;
	}

	cout << answer << endl;
	return 0;
}