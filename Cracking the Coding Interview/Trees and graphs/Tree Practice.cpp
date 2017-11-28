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

    //printf ("%d ", newTree->data) ;

    if (head == NULL)
        return newTree;

    Tree *traverse = head;
    while ( traverse != NULL){

        traverse = ( data < traverse->data ) ? traverse->left : traverse->right;
    }

    traverse = newTree;
    return head;
}

void preorder ( Tree *node){

    if ( node == NULL)
        return;

    if (node->left != NULL)
        preorder(node->left);

    printf("%d ", node->data);

    if (node->right != NULL)
        preorder(node->right);

}

int main(){

    Tree *head = NULL;

    head = InsertTail( head, 5);
    head = InsertTail( head, 4);
    head = InsertTail( head, 6);


    Tree *traverse = head;

    preorder(head);



    return 0;
}