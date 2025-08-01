/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void contar( struct TreeNode *root, int *s );

struct TreeNode* convertBST(struct TreeNode* root) {
    int *s = ( int * )malloc( sizeof(int) );
    *s = 0;
    contar( root, s );
    free(s);
    return root;
}

void contar( struct TreeNode *root, int *s ){
    if ( root == NULL ) {
       return; 
    }
    contar( root->right, s );
    *s += root->val; 
    root->val = *s;
    contar( root->left, s );
}
