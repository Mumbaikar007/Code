/*
	Problem:
		https://projecteuler.net/problem=16
	Referenes:
		http://www.cplusplus.com/forum/general/35482/
*/

# include <iostream>
# include <cmath>
# include <iomanip>
# include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	cout << setprecision (302) << showpoint << fixed; 
	cout << pow(2,1000) << endl;
	*/

	string s = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	int sum = 0;

	for ( int i = 0 ; i < s.size(); i ++){
		sum += s[i] - '0' ;
	}

	cout << sum << endl;

	return 0;
}