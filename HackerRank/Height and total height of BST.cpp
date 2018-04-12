//
// Created by optimus on 17/2/18.
//

# include <iostream>
# include <vector>
#include <algorithm>

using namespace std;

typedef struct Tree {
    int data;
    Tree* left;
    Tree*right;
} Tree;

int gsum = 0;

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

int maxDepth(Tree* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

void printPreorder(struct Tree* node)
{
    if (node == nullptr)
        return;

    /* then recur on left sutree */
    printPreorder(node->left);

    /* first print data of node */
    printf("%d ", node->data);


    /* now recur on right subtree */
    printPreorder(node->right);
}

int getheight(Tree* node)
{
    if (node == nullptr)
        return 0;
    else{
        //gsum += 1 + max(getheight(node->left), getheight(node->right));
        return 1 + max(getheight(node->left), getheight(node->right));
    }

}

int totalheight(Tree* node)
{

    if ( node->left == nullptr && node->right == nullptr)
        return 0;

    int a = 0, b = 0;
    if ( node->left != nullptr)
        a = totalheight(node->left);
    if ( node->left != nullptr)
        b = totalheight(node->right);

    gsum += 1 + max( a, b);
    return 1 + max( a, b);

}

int main(){


    int n;
    cin >> n;
    int a;

    vector<int> vec;

    for ( int i = 0 ; i < n ; i ++){

        cin >> a;

        if ( find(begin(vec), end(vec), a) == vec.end()){
            vec.push_back(a);
        }
    }


    sort ( begin (vec), end(vec));

    Tree *root = nullptr;



    root  = CreateNodes(vec, 0, vec.size()-1);
    //printPreorder(root);

    a = totalheight ( root );
    cout << a << endl << (gsum);
    //inorder(root);

    return 0;
}

/*

 8
 500 400 300 450 425 475 600 550

*/