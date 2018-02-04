
# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
#include <sstream>
# include <vector>
#include <map>

# define RX 4
# define RR 2

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


int integerFromString ( vector<string> words){
    int integer;
    for ( string word : words ){
        if ( stringstream(word) >> integer)
            return integer;
    }
}


int main() {


    vector <string> pseudo_opTable = { "START", "DS", "DC", "USING", "END"};
    vector < pair <string, int> > machine_opTable = { {"L", RX},
                                                      { "A", RX},
                                                      {"ST", RX}
                                                    };
    int locationCounter;
    map <int, int> baseTable;
    map <string, int> symbolTable;

	// Read the file containing the assembler code
    char filename[20];

    cout << "Enter file name: ";
	cin >> filename;

	ifstream reader;
	reader.open(filename);

	if ( !reader ){
		cout << "Error opening input file ...";
		return -1;
	}


	// Reading lines from that file
    string line ;
    while ( !reader.eof() ){

		getline ( reader, line);

        vector <string> words = SplitString(line);

        /*
        cout << words.size() << ": ";
        for ( auto word : words){
            cout << word << " ";
        }
        cout << endl;
        */


        // Check psuedo op table
        vector<string>::iterator inPseudo_op;
        for ( auto instruction : words ){
            inPseudo_op = find( begin ( pseudo_opTable ), end (pseudo_opTable), instruction);
            if ( inPseudo_op != pseudo_opTable.end() ) break;
        }


        //found in pseudo_opTable
        if ( inPseudo_op != pseudo_opTable.end()){

            int position = inPseudo_op - begin(pseudo_opTable);


            switch ( position ){

                // START
                case 0:
                        {
                            locationCounter = integerFromString( words );
                            cout << locationCounter << endl;
                        }
                        break;

                // DS
                case 1: ;

                        break;

                // DC
                case 2: ;
                        break;

                // USING
                case 3: {
                            // since we have only one statement USING *, 15; where * is location counter
                            int registerLocation = integerFromString(words); // not needed
                            baseTable[registerLocation] = locationCounter;
                        }
                        break;

                // END
                case 4: ;
                        break;

            }

        }


        // machine_opTable
        else {

            vector < pair<string, int> >::iterator inMachineop;
            //string inMachineop;
            for ( auto instruction: words){
                inMachineop = find_if ( begin(machine_opTable), end(machine_opTable), [instruction] (const pair<string,int>& p) { return  p.first == instruction; });
                if ( inMachineop != machine_opTable.end()){
                    break;
                }
            }

            locationCounter += inMachineop->second;
            symbolTable[inMachineop->first] = -1 ; // temporary initialization

        }

	}
	

	return 0;
}
