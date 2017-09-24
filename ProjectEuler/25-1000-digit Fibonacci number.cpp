

# include <iostream>
# include <vector>

using namespace std;

void Add( vector <int> * F1, vector<int> * F2){

	int i = 0, carry = 0;

	for ( ; i < (*F1).size() && i < (*F2).size() ; i++){
		carry = (*F1)[i] + (*F2)[i] + carry;
		(*F1)[i] = carry % 10;
		carry /= 10;
	}

	while ( carry != 0){
		carry = (*F1)[i] + carry;
		(*F1)[i] = carry % 10;
		carry /= 10;
		i++;
	}

}



int main(){

	int F1[1010] = { 1 }, F2[1010] = { 1 } ;
	int size1 = 1, size2 = 1;

	int F3[1010] , size3;

	int z = 2 ;

	while ( size1 != 1000 ){
		
		//cout << F1.size()<<endl;
		
		for ( int i = 0 ; i < size1 ; i ++)
			F3[i] = F1[i];

		size3 = size1;
		
		int i = 0, carry = 0;

		for ( ; i < size2 ; i++){
			carry = (F1)[i] + (F2)[i] + carry;
			(F1)[i] = carry % 10;
			carry /= 10;
		}

		// cout << "Carry " << carry  << endl;

		while ( carry != 0){
			carry = (F1)[i] + carry;
			(F1)[i ++] = carry % 10;
			carry /= 10;
		}

		size1 = i;

/*		for ( int i = size1 ; i >= 0 ; --i )
			cout << F1[i] ;
		cout << endl;*/

		for ( int i = 0 ; i < size3 ; i ++)
			F2[i] = F3[i];

		size2 = size3;
			
		z++;

	}

	//Add( &F1, &F2);

	for ( int i = size1 - 1 ; i >= 0 ; --i )
		cout << F1[i] ;

	cout << endl;

/*	for ( int i = size2 ; i >= 0 ; --i )
		cout << F2[i] ;
*/

	cout << z << endl;

	return 0;
}