/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL ;
        if (root->val == key)
        {
            // 0 child :
            if (!root->left && !root->right) return NULL ;
            
            // 1 child :
            if (!root->left || !root->right) return (root->left)? root->left : root->right ;
            
            // 2 child :
            TreeNode* pred = root->right ;
            while(pred->left) pred=pred->left ;
            
            root->val = pred->val ;
            root->right = deleteNode(root->right,pred->val) ;
            
        }
        else if (key > root->val){
            root->right =deleteNode(root->right,key) ;
        }
        else{
            root->left = deleteNode(root->left,key) ;
        }
        return root ;
    }
};