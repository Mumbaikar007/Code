
# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
#include <sstream>
# include <vector>
#include <map>
#include <iomanip>

# define RX 4
# define RR 2

using namespace std;

struct Pass1Print {

    int locaiton, num;
    string instruction;

    Pass1Print ( int locationCounter, int integerInWords, string machineInstruction) :
            locaiton(locationCounter), num(integerInWords), instruction (machineInstruction){};
};

struct SymbolTable {
    string symbol;
    int value, length, reg;

    SymbolTable ( string sym, int val, int len, int regg) :
            symbol (sym), value(val), length(len), reg(regg) {};
};

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

void AssignSymbolValue( vector <SymbolTable> &symbolTable, string symbol, int &locationCounter){

    for ( auto &i : symbolTable ){
        if ( i.symbol == symbol){
            i.value = locationCounter;

            // DLength
            locationCounter += i.length;
            break;
        }
    };

}


int main() {


    vector <string> pseudo_opTable = { "START", "DS", "DC", "USING", "END"};
    vector < pair <string, int> > machine_opTable = { {"L", RX},
                                                      {"A", RX},
                                                      {"ST", RX}
                                                    };
    int locationCounter;
    pair <int, int> baseTable;
    vector<SymbolTable> symbolTable;
    vector < Pass1Print > machineInstruction;

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
    cout << endl << "File has following content ... \n\n";
    string line ;
    while ( !reader.eof() ){

		getline ( reader, line);
        cout << line << endl;


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
                            //cout << locationCounter << endl;
                            SymbolTable symbolTable1 (words[0], locationCounter, 4, 4);
                            symbolTable.push_back(symbolTable1);
                        }
                        break;

                // DS
                case 1: AssignSymbolValue ( symbolTable, words[0], locationCounter);
                        break;

                // DC
                case 2: AssignSymbolValue ( symbolTable, words[0], locationCounter);
                        break;

                // USING
                case 3: {
                            // since we have only one statement for USING => USING *, 15; where * is location counter
                            int registerLocation = integerFromString(words); // not needed
                            baseTable.first = registerLocation ;
                            baseTable.second = locationCounter;
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

            // L <-- length
            int length = inMachineop->second;

            Pass1Print pass1Print(locationCounter, integerFromString(words), inMachineop->first);
            machineInstruction.push_back(pass1Print);

            // symbol in symbol table
            SymbolTable symbolTable1 (words[2], locationCounter, inMachineop->second, inMachineop->second);
            symbolTable.push_back(symbolTable1);

            //  LC <-- LC + L; localtion =>
            locationCounter += length;

        }
	}

    vector<SymbolTable> symbolTableCopy(symbolTable);


    // Sort symbol table
    sort ( begin (symbolTable), end (symbolTable), [] ( SymbolTable s1, SymbolTable s2){
        return s1.value < s2.value;
    });

    // Printing after pass 1
    cout << endl << "Pass 1 ... \n" << endl;
    for ( int i = 0 ; i < machineInstruction.size(); i ++){
        cout << setw(5) << machineInstruction[i].locaiton << setw(10) << machineInstruction[i].instruction << setw(10)
             << machineInstruction[i].num << ",_(" << baseTable.second << "," << baseTable.first
             << ")" << endl;
    }
    for ( vector<SymbolTable>::iterator it = begin(symbolTable) + 1; it != end(symbolTable) ; it++){
        cout << setw(5) << it->value  << setw(10) << it->symbol << endl;
    }
    cout << endl;


    cout << "Symbol Table ... \n";
    cout << setw(10) << "Symbol" << setw(10) << "Value" << setw(10) << "Length"
            << setw(10) << "Register" << endl;
    for ( auto i: symbolTable){
        cout << setw(10) << i.symbol << setw(10) << i.value << setw(10) << i.length << setw(10) << "R" << endl;
    }
	cout << endl;

    cout << "Base table ... \n";
    cout << setw(10) << "Register" << setw(10) << "Value" << endl;
    cout << setw(10) << baseTable.second << setw(10) << baseTable.first << endl;
    cout << endl;



    // After pass 2
    cout << "Pass 2 ... \n";
    for ( int i = 0 ; i < machineInstruction.size(); i ++){
        cout << setw(5) << machineInstruction[i].locaiton << setw(10) << machineInstruction[i].instruction << setw(10)
             << machineInstruction[i].num << "," << symbolTableCopy[i+1].value <<"(" << baseTable.second << "," << baseTable.first
             << ")" << endl;
    }
    for ( vector<SymbolTable>::iterator it = begin(symbolTable) + 1; it != end(symbolTable) ; it++){
        cout << setw(5) << it->value  << setw(10) << it->symbol << endl;
    }
    cout << endl;

	return 0;
}
