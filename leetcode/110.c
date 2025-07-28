/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 Pegar o fator de balanceamento
 */

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


bool isBalanced(struct TreeNode* root) {
    int b;

    if ( root == NULL ){
        return true;
    }
    b = Altura( root->left ) - Altura( root->right );
    
    if ( b < -1 || b > 1 ) {
        return false;
    } else {
        return isBalanced( root->left ) && isBalanced( root->right );
    }
}