# include <iostream>

using namespace std;

void Increase( int *number){
	cout << "Address: " << number << endl;
	cout << "Value: " << *number << endl;

	cout << "Increase: " << ++(*number) << endl;


}

int main(){

	int a = 5;
	
	Increase(&a);

	cout << "Main's a: " << a << endl;


	return 0;
}