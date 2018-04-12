

# include <iostream>
# include <vector>

using namespace std;

int main(){
	
	int number = 2;
	long int answer = 0;

	vector <int> abundant;
	vector <int> nos (28124);

	for ( ; number <= 28123 ; ++ number){
		
		long int sum = 1;
		int a = 2 , gameChanger = number;
		
		while ( a < gameChanger){
			if ( number % a == 0  ){	
				gameChanger = number / a;\
				if ( a != gameChanger){
					sum += a + gameChanger ;
				}
				else 
					sum += a;
			}
			++ a;
		}

		if ( sum > number){
			abundant.push_back(number);
		}

	}

	for ( int i = 0 ; i < abundant.size() ; i ++){
		for ( int j = i ; j < abundant.size() ; j ++){
			if (abundant[i] + abundant[j] <= 28123)
				nos[abundant[i] + abundant[j]] = 1;
		}
	}

	for  ( int i = 0 ; i < 28124 ; i ++){
		if (!nos [i])
			answer += i;		
	}

	cout << answer << endl ;

	return 0;
}