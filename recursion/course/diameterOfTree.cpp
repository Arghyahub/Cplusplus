class Solution {
    int getdia(TreeNode* root, int &ans)
    {
        if (root==NULL)
            return 0 ;
        
        int left = getdia(root->left,ans) ;
        int right = getdia(root->right,ans) ;
        ans = max(ans,left+right) ;
        
        return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getdia(root,ans);
        return ans ;
    }
};