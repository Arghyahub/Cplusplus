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
    void recoverTree(TreeNode* curr) {
        
        TreeNode* prev = NULL ;
        TreeNode* first = NULL ;
        TreeNode* second = NULL ;
        
        // using morris traversal
        
        while(curr)
        {
            if (curr->left==NULL)
            {
                if (prev!=NULL && prev->val > curr->val )  // IF PREV IS NOT NULL AND PREV VALUE IS GREATER THAN CURRENT VALUE
                {
                    if (first==NULL)
                    {
                        first=prev ;
                        second = curr ;
                    }
                    else
                        second = curr ;
                }
                prev = curr ;
                curr = curr->right ;
            }
            else
            {
                TreeNode* pred = curr->left ;
                
                while(pred->right!=NULL && pred->right!=curr)
                    pred=pred->right ;
                
                if (pred->right==NULL){
                    pred->right = curr ;
                    curr = curr->left ;
                }
                else                            // ALWAYS DO WORK WHILE RETURNING BACK
                {
                    pred->right= NULL ;
                    if (prev->val > curr->val)      // SAME, IF PREV > CURR THEN UPDATE FIRST AND SECOND
                    {
                        if (first == NULL)
                        {
                            first = prev ;
                            second = curr ;
                        }
                        else
                            second = curr ;
                    }
                    
                    prev = curr ;
                    curr = curr->right ;
                }
            }
        }
        
        int f = first->val ;
        first->val = second->val ;
        second->val = f ;
        
    }
};