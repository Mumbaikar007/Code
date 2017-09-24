

# include <iostream>

using namespace std;

int Factorial ( int *a, int number , int size) {

	int b = 2;
	while ( b <= number){

		int carry = 0;

		for ( int i = 1; i <= size ; i++){
			carry = (a[i] * b) + carry ;
			a[i] = carry % 10;
			carry /= 10 ;	
		}

		while ( carry ){
			a[++size] = carry % 10;
			carry /= 10;
		}

		b ++;
	}

	return size;

}

int main(int argc, char const *argv[])
{
	
	int a[500] ;
	a[1] = 1;
	int size = 1 ;

	size = Factorial ( a, 100, size);

	int sum = 0;

	for ( int i = size; i > 0 ; --i)
			sum += a[i] ;

	cout << sum << endl;


	return 0;
}