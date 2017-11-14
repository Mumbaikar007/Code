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

    int last = 4;
    Node *p1, *p2;
    p1 = p2 = head;

    for ( int i = 0 ; i < last ; i ++)
        p1 = p1->next;

    while (p1 != nullptr){
        p1 = p1->next;
        p2 = p2->next;
    }

    cout << p2->data << endl;
    return 0;
}