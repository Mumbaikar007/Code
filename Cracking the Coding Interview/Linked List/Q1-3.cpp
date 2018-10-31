//
// Created by optimus on 14/11/17.
//

# include <iostream>

using namespace std;

typedef struct Node {
    int data;
    Node *next;
};

Node *InsertTail ( Node *head, int data){

    Node *newNode = (Node *) malloc(sizeof (Node));
    newNode->data = data;
    newNode->next = nullptr;

    if ( head == nullptr)
        return newNode;

    else {

        Node *traverse = head;
        while ( traverse -> next != nullptr )
            traverse = traverse->next;

        traverse->next = newNode;

    }

    return head;

}


int main(){

    Node *head = nullptr;
    cout << "Enter 10 elements... \n";
    int number;
    for ( int i = 0 ; i < 10 ; i ++){
        cin >> number;
        head = InsertTail( head, number);
    }


    Node *traverse = head;
    for  (int i = 0 ; i < 4 ; i ++)
        traverse = traverse->next;


    Node *del = traverse;
    del->data = del->next->data;
    del->next = del->next->next;

    traverse = head;
    while ( traverse != nullptr){
        cout << traverse->data << " ";
        traverse = traverse->next;
    }

    return 0;
}