//
// Created by optimus on 16/11/17.
//

# include <iostream>
# include <stack>

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


string isPalindrome ( Node *head){

    stack <int> s1;

    Node *fastRunner = head, *slowRunner = head;

    while ( fastRunner != nullptr && fastRunner->next != nullptr){
        s1.push(slowRunner->data);

        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
    }

    if ( fastRunner != nullptr)
        slowRunner = slowRunner->next;


    while ( slowRunner != nullptr){
        int top = s1.top();
        cout << top << " " << slowRunner->data <<  endl;
        if (top != slowRunner->data){
            cout << top << " " << slowRunner->data <<  endl;
            return "NO";
        }

        s1.pop();
        slowRunner = slowRunner->next;
    }



    return "YES";
}

int main(){

    Node *head = NULL;

    int size, number;
    cin >> size;

    for ( int i = 0 ; i < size; i ++){
        cin >> number;
        head = InsertTail( head, number);
    }


    cout << isPalindrome (head) << endl;


    return 0;
}

