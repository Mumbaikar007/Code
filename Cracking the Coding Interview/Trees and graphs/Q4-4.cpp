//
// Created by optimus on 8/12/17.
//

# include <iostream>
#include <climits>

using namespace std;


typedef struct Tree {
    int data;
    struct Tree *left, *right;

} Tree ;

struct Tree *InsertTail ( Tree *head, int data ){

    Tree *newTree = ( Tree *) malloc( sizeof (Tree) );

    newTree -> data = data;
    newTree -> left = newTree->right =  NULL;

    //printf ("%d ", newTree->data) ;

    if (head == NULL)
        return newTree;

    Tree *traverse = head, *behind = head;
    while ( traverse != NULL){
        behind = traverse;
        traverse = ( data < traverse->data ) ? traverse->left : traverse->right;
    }

    if ( data < behind->data){
        behind->left = newTree;
    }
    else{
        behind->right = newTree;
    }
    return head;
}


int checkHeight( Tree *root ){
    if (root == NULL)
        return -1;

    int left = checkHeight(root->left);
    if ( left == INT_MIN)
        return left;

    int right = checkHeight(root->right);
    if ( right == NULL)
        return right;

    if ( abs(right-left) > 1 )
        return INT_MIN;

    else
        return max(left, right) + 1;
}

bool isBalanced ( Tree *root){
    return checkHeight(root) != INT_MIN;
}



int main(){


    Tree *head = NULL;

    head = InsertTail( head, 5);
    head = InsertTail( head, 4);
    head = InsertTail( head, 6);


    cout << isBalanced (head);

    return 0;
}