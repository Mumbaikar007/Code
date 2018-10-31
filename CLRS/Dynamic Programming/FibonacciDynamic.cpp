

# include <iostream>
# include <vector>

using namespace std;

int FibonacciTwo ( vector <int> &fibSeries, int position){

	if ( fibSeries [position] > 0)
		return fibSeries[position];

 	fibSeries [position] = FibonacciTwo ( fibSeries, position - 1) + FibonacciTwo ( fibSeries, position - 2)  ;

 	return fibSeries[position] ;
}



int FibonacciOne ( vector <int> &fibSeries, int position){

	fibSeries[2] = fibSeries[1] = 1;

	return FibonacciTwo ( fibSeries , position);
}


int FibonacciBottomUp ( std::vector<int> &fib, int position){

	if ( position <= 1)
		return position;

	for ( int i = 2 ; i < position ; i ++){

		fib[i] = fib [ position - 1] + fib [ position - 2] ;

	}

	return fib[position] ;

}


int main(){

	int n = 9;

	std::vector<int> fibSeries (n + 1) ;

//	Top-Down Apporach ... 

	cout << "Top-Down : " << FibonacciOne ( fibSeries, n ) << endl;


//	Bottom-Up Apporach ...

	cout << "Bottom-Up : " << FibonacciBottomUp ( fibSeries, n) << endl;

	cout << endl;

	return 0;
}