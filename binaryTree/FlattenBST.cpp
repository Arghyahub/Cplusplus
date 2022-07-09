/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorderTraverse(TreeNode<int>* root, vector<int> &ans)
{
    if (root==NULL)
        return ;
       
    inorderTraverse(root->left,ans) ;
    ans.push_back(root->data) ;
    inorderTraverse(root->right,ans) ;
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans ;
    inorderTraverse(root,ans) ;
    
    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]) ;
    
    TreeNode<int>* curr = newRoot ;
    
    int i=1 ;
    for (int i=1; i<ans.size(); i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(ans[i]) ;
        curr->left = NULL ;
        curr->right = temp ;
        
        curr = temp ;
    }
    curr->left = NULL ;
    curr->right = NULL ;
    
    
    return newRoot ; 
}
