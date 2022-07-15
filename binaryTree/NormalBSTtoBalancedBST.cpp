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
    
    int mid = (s+e)/2 ;                // BASICALLY IN INORDER TRAVERSAL THE CENTERAL NODE IS SUITABLE TO BECOME THE ROOT NODE
    TreeNode<int>* root = new TreeNode<int> (ans[mid]) ;
    root->left = inorderToBST(s,mid-1,ans) ;       // THE NEXT NODE OF THE NEW LEVEL WILL RESIDE UNDER MINI TO MID-1 (SMALLER THAN MID)
    root->right = inorderToBST(mid+1,e,ans) ;
     
    return root ;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> ans ;
    inorderTraverse(root,ans) ; // THE GIVEN TREE IS ALSO A BST SO WE CAN DO INORDER TRAVERSAL TO GET ELEMENTS IN SORTED ORDER
    
    return inorderToBST( 0 , ans.size() - 1 , ans) ;

}
