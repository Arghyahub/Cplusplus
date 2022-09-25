class Solution {
    bool checkSym(TreeNode* root1, TreeNode* root2)
    {
        if (root1==NULL && root2==NULL) return true;
        else if (root1==NULL || root2==NULL) return false;
        
        if (root1->val != root2->val) return false;
        
        bool left = checkSym(root1->left,root2->right);
        if (left==false) return false;
        bool right = checkSym(root1->right,root2->left) ;
        if (right==false) return false;
        
        return true ;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root->left==NULL && root->right==NULL)
            return true;
        else if (root->left==NULL || root->right==NULL)
            return false;
        
        
        return checkSym(root->left,root->right);
    }
};