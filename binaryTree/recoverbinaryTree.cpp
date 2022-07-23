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
    void inorderpush(TreeNode* root, vector<TreeNode*> &ans)
    {
        if (root==NULL)
            return ;
        
        inorderpush(root->left,ans) ;
        
        ans.push_back(root) ;
        
        inorderpush(root->right,ans) ;
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ans ;
        
        inorderpush(root,ans) ;
        
        vector<pair<int,int>> s(ans.size()) ;
        
        for (int i=0; i<ans.size(); i++)
        {
            s[i].first = ans[i]->val ;
            s[i].second =  i ;
        }
        sort(s.begin(),s.end()) ;
        
        for (int i=0; i<ans.size(); i++)
        {
            if (s[i].second == i)
                continue ;
            else
            {
                int swapindex = s[i].second ;
                swap(ans[i]->val,ans[swapindex]->val) ;
                swap(s[i],s[swapindex]) ;
                
                i-- ;
            }
        }
        
    }
};