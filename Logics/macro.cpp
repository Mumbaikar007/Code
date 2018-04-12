
# include <iostream>
# include <fstream>
# include <string>
#include <sstream>
# include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct MNT{

    int index;
	string card;
	int MDTIndex, ALAIndex;

    MNT ( int indexx, string cardd, int MDTIndexx, int ALAIndexx ) :
            index(indexx), card(cardd), MDTIndex (MDTIndexx), ALAIndex ( ALAIndexx ){};
};

struct ALA{

    int index;
	string argument;

    ALA ( int indexx, string arg) : index (indexx), argument(arg) {};
};

struct MDT {

    int index;
	string card;
    int firstop;

    MDT ( int indexx, string cardd, int firstopp) :
            index( indexx ), card(cardd), firstop(firstopp) {};
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

int main(){
	
	// Read the file containing the assembler code
   	char filename[20];

   	cout << "Enter file name: ";
  	cin >> filename;

	//Pass 1
  	ifstream reader, reader2;
  	reader.open(filename);
    reader2.open(filename);

  	if ( !reader ){
     	cout << "Error opening input file ...";
     	return -1;
  	}
  	
  	// Reading lines from that file
   	cout << endl << "File has following content ... \n\n";
   	string line ;
   	
   	int MNTC = 1, MDTC = 1, ALAT = 1, MDTP = 1, ALATT = 1, MDTT = 1;
	vector <MNT> mnt = { MNT ( 0 , "abc", 0, 0 )};
	vector <ALA> alaPassOne = { ALA ( 0, "abc" )}, alaPassTwo = { ALA ( 0, "abc" )};
	vector <MDT> mdtPassOne = { MDT ( 0, "abc", 0)}, mdtPassTwo = { MDT ( 0, "abc", 0 )};
	
	vector <string> instructionsArray = { "L", "S", "A"};
    int printPassOne = 1, macroArgumentStart;


    line = "";
    while ( !reader2.eof()){
        getline ( reader2, line);
        cout << line << endl;
    }

    line = "";

	while ( !reader.eof() ){

     	getline ( reader, line);
        //cout << line << endl;
        vector <string> words = SplitString(line);

		if ( line.find("MACRO") != string::npos ){

            int macroLine = 1;



			while ( getline ( reader, line)){

                vector <string> words = SplitString(line);
                //cout << line << endl;

                if ( words[0] == "MEND"){
                    mdtPassOne.push_back( MDT( MDTC ++ , "MEND", 0  ));
                    break;
                }


                if ( macroLine ){


                    // Insert in MNT
                    MNT mnt1 = MNT ( MNTC ++, words[0], MDTC, ALAT);
                    mnt.push_back( mnt1 );

                    // Prepare ALA
                    macroArgumentStart = ALAT;
                    for ( int i = 1; i < words.size() - 1; i ++)
                        alaPassOne.push_back( ALA (ALAT ++, words[i].substr( 0 , words[i].size() -1)));
                    alaPassOne.push_back( ALA ( ALAT ++ , words[words.size()-1]));


                    // Insert in MDT
                    string mdtcard = words[0] + " ";
                    for ( int i = 1 ; i < words.size()-1 ; i ++)
                        mdtcard += ( to_string(i + macroArgumentStart - 1) ) + ", ";
                    mdtcard += to_string(macroArgumentStart + words.size()-1 - 1);

                    mdtPassOne.push_back( MDT( MDTC ++ , mdtcard, 0)); // macro name line

                    macroLine = 0;
                }

                else {

                    auto it = find_if (begin(alaPassOne), end (alaPassOne), [words] ( ALA ala1) { return words[2] == ala1.argument ;});
                    //cout << endl << it - begin(ala) << endl << endl;
                    int position = it - begin(alaPassOne);
                    string mdtcard = (words[0] + " " + words[1] + " " + to_string(position));
                    mdtPassOne.push_back( MDT( MDTC ++ , mdtcard, position));

                }

			}
			
		}

        else {

            auto itStart = find( begin(words), end(words), "START");
            if ( itStart != words.end())
                continue;

            itStart = find( begin(words), end(words), "END");
            if ( itStart != words.end())
                continue;

            if ( printPassOne ){

                // Pass 1
                cout << endl << "After Pass 1... " << endl << endl;

                cout << "Macro Name Table ...\n";
                cout << setw(10) << "MNT Index" << setw(15) << "Macro Card" << setw(15) << "MTD Index" << endl;
                for ( int i = 1 ; i < mnt.size(); i ++ ){
                    cout << setw(10) << mnt[i].index << setw(15) << mnt[i].card << setw(15) << mnt[i].MDTIndex << endl;
                }

                cout << endl << "Macro Name Table ...\n";
                cout << setw(10) << "ALA Index" << setw(15) <<  "ALA Argument" << endl;
                for ( int i = 1 ; i < alaPassOne.size(); i ++)
                    cout << setw(10) << alaPassOne[i].index << setw(15) << alaPassOne[i].argument << endl;

                cout << endl << "Macro Name Table ...\n";
                cout << setw(10) << "MDT Index" << setw(15) <<  "MDT Card" << endl;
                for ( int i = 1 ; i < mdtPassOne.size(); i ++ )
                    cout << setw(10) << mdtPassOne[i].index << setw(15)  << mdtPassOne[i].card << endl;

                printPassOne = 0;
            }


            auto it = find_if ( begin (mnt), end (mnt), [words] ( MNT mnt1) { return words[0] == mnt1.card;});
            MDTP = it->MDTIndex + 1;
            int macroArgRef = it->ALAIndex;
            macroArgumentStart = ALATT;
            for ( int i = 1; i < words.size() - 1; i ++)
                alaPassTwo.push_back( ALA (ALATT ++, words[i].substr( 0 , words[i].size() -1)));
            alaPassTwo.push_back( ALA ( ALATT ++ , words[words.size()-1]));

            string wwords = "";
            for ( string i : words )
                wwords += (i + " ");
            mdtPassTwo.push_back( MDT ( MDTT ++, wwords, 0 ));

            while ( mdtPassOne[MDTP].card != "MEND" ){

                int argument = mdtPassOne[MDTP].firstop - macroArgRef + macroArgumentStart;

                mdtPassTwo.push_back( MDT ( MDTT++, mdtPassOne[MDTP].card, argument));
                MDTP++;
            }
            mdtPassTwo.push_back( MDT ( MDTT ++,  "MEND", 0 ));


        }
		
	}



    // Pass 2
    cout << endl << endl;
    cout << endl << "After Pass 2... " << endl << endl;

    cout << "Macro Name Table ...\n";
    cout << setw(10) << "MNT Index" << setw(15) << "Macro Card" << setw(15) << "MTD Index" << endl;
    for ( int i = 1 ; i < mnt.size(); i ++ ){
        cout << setw(10) << mnt[i].index << setw(15) << mnt[i].card << setw(15) << mnt[i].MDTIndex << endl;
    }

    cout << endl << "Macro Name Table ...\n";
    cout << setw(10) << "ALA Index" << setw(15) <<  "ALA Argument" << endl;
    for ( int i = 1 ; i < alaPassTwo.size(); i ++)
        cout << setw(10) << alaPassTwo[i].index << setw(15) << alaPassTwo[i].argument << endl;

    cout << endl << "Macro Name Table ...\n";
    cout << setw(10) << "MDT Index" << setw(18) <<  "MDT Card" << endl;
    for ( int i = 1 ; i < mdtPassTwo.size(); i ++ ){
        cout << setw(10) << mdtPassTwo[i].index << "          " << mdtPassTwo[i].card  <<
                ( mdtPassTwo[i].firstop != 0 ? "\b\b" + alaPassTwo[mdtPassTwo[i].firstop].argument : "")<< endl;
    }

    return 0;
}
