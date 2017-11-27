//
// Created by optimus on 27/11/17.
//


# include <stdio.h>
# include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree *left, *right;

} Tree ;

struct Tree *InsertTail ( Tree *head, int data ){

    Tree *newTree = ( Tree *) malloc( sizeof (Tree) );

    newTree -> data = data;
    newTree -> left = newTree->right =  NULL;

    printf ("%d ", newTree->data) ;

    if (head == NULL)
        return newTree;

    Tree *traverse = head;
    while ( traverse != NULL){
        traverse = ( data < traverse->data ) ? traverse->left : traverse->right;
    }

    traverse = newTree;
    return head;
}

//preorder left

int main(){

    Tree *head = NULL;

    head = InsertTail( head, 5);


    Tree *traverse = head;



    printf("%d ", traverse->data);

    return 0;
}