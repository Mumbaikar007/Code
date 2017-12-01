//
// Created by optimus on 26/11/17.
//

# include <iostream>
# include <vector>

using namespace std;

typedef struct Tree {
    int data;
    Tree* left;
    Tree*right;
} Tree;

Tree *CreateNodes ( vector<int> vec, int start, int end){

    if ( end < start )
        return nullptr;

    int mid = (start + end) / 2;

    Tree *newNode = (Tree *) malloc(sizeof(Tree));
    newNode->data = vec[mid];
    newNode->left = CreateNodes(vec, start, mid-1);
    newNode->right = CreateNodes(vec, mid+1, end);


    return newNode;

}

void inorder ( Tree *node){

    if ( node == nullptr)
        return;

    if (node->left != nullptr)
        inorder(node->left);

    printf("%d ", node->data);

    if (node->right != nullptr)
        inorder(node->right);

}

int main(){


    int n;
    cin >> n;

    vector<int> vec(n);

    for ( int i = 0 ; i < n ; i ++)
        cin >> vec[i];

    Tree *root = nullptr;

    root  = CreateNodes(vec, 0, vec.size()-1);

    inorder(root);

    return 0;
}
