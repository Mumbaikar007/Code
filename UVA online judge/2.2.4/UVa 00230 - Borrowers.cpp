//
// Created by optimus on 27/1/18.
//

# include <iostream>
#include <vector>

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


}


int main(){


    return 0;
}