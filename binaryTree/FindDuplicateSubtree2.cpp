class Solution {
    vector<TreeNode*> ans;
    unordered_map<string,int> mp;
    string preorder(TreeNode* root){
        if (!root){
            return "x";
        }
        string s ='n'+to_string(root->val) +'l'+preorder(root->left) +'r'+preorder(root->right) ;
        mp[s]++;
        if (mp[s]==2)
            ans.push_back(root) ;
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) return {} ;
        preorder(root) ;
        return ans;
    }
};
