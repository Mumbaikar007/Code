//
// Created by optimus on 6/3/18.
//

# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
# include <sstream>
# include <vector>
# include <map>
# include <iomanip>

using namespace std;

vector<string> SplitString ( string line){

   vector<string> words_in_line;

   istringstream iss(line);
   string word;
   while ( iss >> word ){
       words_in_line.push_back(word);
   }

   return words_in_line;
}

void find_and_replace_string(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}


int main(){


	vector <string> keywords = { "if", "then"},  verbs = { "like" , "hate" };
	vector <string> actions = { "they" } ;
	vector < pair <int, string> > symbolTable;
	int symbols = 1;
    string forValidation = "";


	string line;
	while ( getline ( cin, line) ){

		vector<string> words = SplitString ( line );
		if ( line.find('$') != string::npos){
            cout << "eof";
            break;
        }


		for ( string word : words ){

            auto it = find ( begin (keywords), end (keywords), word);
			if ( it != end( keywords ) ){
				cout << "K ";
                forValidation += ( it - begin(keywords) == 0 ? "i" : "t");
			}

			else if ( find ( begin ( verbs ), end (verbs) , word ) != end (verbs ) ){
				cout << "V ";
                forValidation += "V";
			}


			else if ( find ( begin (actions), end (actions), word) != end ( actions) ) {
				cout << "A ";
                forValidation += "A";
			}

			else {

				auto it = find_if ( begin (symbolTable), end (symbolTable), [word] ( const pair<int, string> &p) {
						return p.second == word;
					  });

				if ( it != end(symbolTable) ){
					cout << "N," << it->first << " ";
                    forValidation += "N";
				}

				else {
					word = ( word[word.size()-1] == '.' ? word.substr(0, word.size()-1) : word );
					symbolTable.push_back( make_pair(symbols++, word) );
					cout << "N," << symbols-1 << " ";
                    forValidation += "N";
				}

			}

		}

		if ( line[line.size()-1] == '.' ){
			cout << "op ";
            forValidation += ".";
		}
		cout << endl;
	}
    cout << endl;

    string P = "NVN";

    find_and_replace_string( forValidation, P, "P");

    string S = "iPtAN.";

    find_and_replace_string( forValidation, S, "S");

    find_and_replace_string( forValidation, "S", "");

    if ( forValidation.size() != 0 ){
        cout << "Invalid Code!!";
    }
    else {
        cout << "Valid Code!!";
    }

	return 0;
}

/*

 	if dogs hate cats
 	then they bark.
 	if cats like milk
 	then they drink.
 	$


*/