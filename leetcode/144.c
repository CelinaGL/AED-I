/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preordem( int *ordem, struct TreeNode *root, int *returnSize ) {
    if ( root != NULL ) {
        ordem[*returnSize] = root->val;
        (*returnSize)++;
        preordem( ordem, root->left, returnSize );
        preordem( ordem, root->right, returnSize );
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ordem = ( int * )malloc( sizeof(int) * 100 );
    *returnSize = 0;

    preordem( ordem, root, returnSize );
    
    return ordem; 
}

