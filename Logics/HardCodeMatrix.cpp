# include <iostream>

using namespace std;

int main(){
	
	int a[] = {10, 15} ;

	cout << *a << endl;
	//cout << *(++a) << endl;   	//error: lvalue required as increment operand
	int *p;
	p = a;

	cout << *(p+1) << endl;


	return 0;
}