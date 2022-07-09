/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorderTraverse(TreeNode<int>* root, vector<int> &ans)
{
    if (root==NULL)
        return ;
    
    inorderTraverse(root->left,ans) ;
    ans.push_back(root->data) ;
    inorderTraverse(root->right,ans) ;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &ans)
{
    if (s > e)
        return NULL ;
    
    int mid = (s+e)/2 ;
    TreeNode<int>* root = new TreeNode<int> (ans[mid]) ;
    root->left = inorderToBST(s,mid-1,ans) ;
    root->right = inorderToBST(mid+1,e,ans) ;
     
    return root ;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> ans ;
    inorderTraverse(root,ans) ;
    
    return inorderToBST( 0 , ans.size() - 1 , ans) ;

}
