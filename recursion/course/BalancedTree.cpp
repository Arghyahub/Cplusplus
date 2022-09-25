class Solution {
    
    pair<int,bool> checkBalanced(TreeNode* root)
    {
        if (!root) return {0,true} ;
        pair<int,bool> left = checkBalanced(root->left) ;
        pair<int,bool> right = checkBalanced(root->right);
        if (!left.second | !right.second ) return {0,false};
        
        if (abs(left.first-right.first)>1) return {0,false};
        else return { max(left.first,right.first)+1 , true};
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root).second;
    }
};