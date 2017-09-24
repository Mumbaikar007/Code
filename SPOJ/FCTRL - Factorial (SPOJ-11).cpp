/*
	Problem:
		http://www.spoj.com/problems/FCTRL/

	References:
		http://mathforum.org/library/drmath/sets/select/dm_factorial_list.html
*/

# include <iostream>

using namespace std;

int main()
{
	int test;
	cin >> test;
	while (test--){
		long int number;
		cin >> number;
		int zeros = 0, logic = 5;
		while (logic <= number){
			int dividend = number / logic;
			zeros += dividend;
			logic *= 5;
		}
		cout << zeros << endl;
	}
	return 0;
}





