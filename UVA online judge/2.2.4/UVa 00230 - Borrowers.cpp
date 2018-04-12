//
// Created by optimus on 27/1/18.
//

# include <iostream>
#include <vector>
#include <algorithm>
# include <map>

using namespace std;

struct book {

    string title, author;

    bool operator<(const book& other) const {
        if ( author != other.author)
            return author < other.author;
        return title < other.title;
    }

};


void ReadInBooks ( vector <book> & allbook){

    string temp;
    book currentBook;

    while ( cin >> temp, temp != "END"){

        currentBook.title = temp.substr( 1, temp.size() - 1);

        while ( *(temp.end() - 1) != '"'){
            cin >> temp;
            currentBook.title += ( ' ' + temp);
        }

        currentBook.title = currentBook.title.substr(0, currentBook.title.size() - 1);
        //cout << currentBook.title << endl;

        cin >> temp;
        cin.ignore();

        getline(cin , currentBook.author);
        allbook.push_back(currentBook);
    }

}

enum bookStatusEnum { available, borrowed, returned };

int main(){

    vector<book> allbook;
    ReadInBooks(allbook);

    int numBooks = allbook.size();
    sort ( begin(allbook), end(allbook));

    vector <bookStatusEnum> bookStatus ( numBooks, available);

    map <string,int> positionOfAllBooks;
    for ( int i = 0 ; i < numBooks; i ++)
        positionOfAllBooks[allbook[i].title] = i;

    vector <bool> borrowed ( numBooks, false);
    vector <bool> returned ( numBooks, false);


    string command, bookName;
    while ( cin >> command, command != "END"){

        if ( command == "BORROW"){
            cin.ignore();
            getline(cin, bookName);
            bookName = bookName.substr( 1, bookName.size()-2);
            int pos = positionOfAllBooks[bookName];
            //cout << bookName << " " << pos << endl;
            borrowed[pos] = true;
            returned[pos] = false;
        }

        else if ( command == "RETURN"){
            cin.ignore();
            getline(cin, bookName);
            bookName = bookName.substr( 1, bookName.size()-2);
            int pos = positionOfAllBooks[bookName];
            returned[pos] = true;
        }

        else {


            //for ( int i = 0 ; i < numBooks; i ++){
             //   cout << borrowed[i] << " ";
            //}

            int previous = -1;
            for ( int i = 0 ; i < numBooks; i ++ ){

                if (!borrowed[i]){
                    previous = i;
                }

                else if ( returned[i] ){
                    if  ( previous == -1 ){
                        cout << "Put \"" << allbook[i].title << "\" first\n";
                    }
                    else
                        cout << "Put \"" << allbook[i].title << "\" after \"" << allbook[previous].title << "\"\n";

                    returned[i] = false;
                    borrowed[i] = false;
                    previous = i;
                }


            }
            cout << "END\n";
        }

    }

    return 0;
}