# include <iostream>
# include <vector>

using namespace std;

struct RankScore
{
	long int score;
	long int rank;
};



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int rankNow = 0, previous = -1;

	vector <RankScore> vec(n + 1);
	for ( int i = 0 ; i < n ; i ++){
		cin >> vec[i].score;
		if (previous != vec[i].score){
			vec[i].rank =  ++ rankNow ;
			previous = vec[i].score;
		}
		else {
			vec[i].rank = rankNow;
		}
	}

	int m;
	cin >> m;
	rankNow ++;
	int j = n - 1;

	vector<long int> alice(m);
	for ( int i = 0 ; i < m; i ++){
		
		cin >> alice[i];

		while ( j >= 0 && alice[i] >= vec[j].score ){
			//cout << vec[j].score << " " << vec[j].rank << endl; 
			j--;
			if ( vec[j].rank != vec[j+1].rank)
				rankNow --;

			//cout << vec[j].score << " " << vec[j].rank << endl;

		}



		cout << rankNow << endl; 

	}




	return 0;
}