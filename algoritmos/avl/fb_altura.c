#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int Altura( struct TreeNode* root );
int FB( struct TreeNode* root );

int main(){

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 63;
    
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    
    root->right = NULL;
    
    root->left->left = NULL;

    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 19;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    int b, a;

    a = FB( root->left );
    b = FB( root );
    printf("%d %d", b, a);

    return 0;
}

int Altura( struct TreeNode* root ) {
    int esq, dir;

    if ( root == NULL ) {
        return 0;
    }

    esq = Altura( root->left );
    dir = Altura( root->right );

    if ( esq > dir ) {
        return esq + 1; 
    } else { 
        return dir + 1;
    }
}

int FB( struct TreeNode* root ) {
    if ( root == NULL ){
        return 0;
    }
    return Altura( root->left ) - Altura( root->right );
}