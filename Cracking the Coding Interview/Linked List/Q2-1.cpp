//
// Created by optimus on 14/11/17.
//

# include <iostream>
# include <set>
# include <iterator>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
};


Node *InsertTail ( Node *head, int data ){

    Node *newNode = ( Node *) malloc( sizeof (Node) );

    newNode -> data = data;
    newNode -> next = NULL;

    Node *traverse = head;
    if ( traverse == NULL){
        return newNode;
    }
    else {

        while (traverse->next != NULL) {
            traverse = traverse->next;
            //printf("%d ", traverse->data);
        }

        traverse->next = newNode;
    }

    return head;
}


int main(){


    Node *head = NULL;


    int number;
    cout << "Enter 10 elements ... \n";
    for ( int i = 0 ;i < 10 ; i ++){
        cin >> number;
        head = InsertTail( head, number);
    }

    Node *traverse = head;
    cout << "The List \n";
    while ( traverse != NULL ) {
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
    cout << "\n";
    // To remove Duplicates
    set <int> myset;
    Node *previous = NULL;

    traverse = head;
    while ( traverse != NULL){
        if (myset.count(traverse->data) ) {
            previous->next = traverse->next;
        }
        else{
            myset.insert(traverse->data);
            previous = traverse;
        }
        traverse = traverse->next;

    }

    traverse = head;
    cout << "Duplicates removed ... \n";
    while ( traverse != NULL ) {
        cout << traverse->data << " ";
        traverse = traverse->next;
    }


    return 0;
}