//
// Created by optimus on 11/11/17.
//

# include <iostream>

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


    head = InsertTail( head, 5);
    head = InsertTail( head, 25);
    head = InsertTail( head, 125);
    head = InsertTail( head, 625);


    Node *traverse = head;

    while ( traverse->next != NULL){
        printf("%d ", traverse->data );
        traverse = traverse->next;
    }
    printf("%d ", traverse->data);

    return 0;
}

