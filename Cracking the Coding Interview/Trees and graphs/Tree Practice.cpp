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

void inorder ( Tree *node){

    if ( node == NULL)
        return;

    if (node->left != NULL)
        inorder(node->left);

    printf("%d ", node->data);

    if (node->right != NULL)
        inorder(node->right);

}

int main(){

    Tree *head = NULL;

    head = InsertTail( head, 5);
    head = InsertTail( head, 4);
    head = InsertTail( head, 6);


    Tree *traverse = head;

    inorder(head);



    return 0;
}