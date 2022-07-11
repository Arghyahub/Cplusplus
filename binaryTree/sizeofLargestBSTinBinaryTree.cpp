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

class info
{
    public:
    int maxi ;
    int mini ;
    bool isBST ;
    int size ;
};

info solve(TreeNode<int>* root , int &ans)
{
    if (root==NULL)
        return {INT_MIN,INT_MAX,true,0} ;
    
    info left = solve(root->left,ans) ;
    info right = solve(root->right,ans) ;
    
    info currnode;
    currnode.size = left.size + right.size + 1 ;
    currnode.maxi = max(right.maxi , root->data) ;
    currnode.mini = min(left.mini , root->data) ;
    
    currnode.isBST = left.isBST && right.isBST && (root->data < right.mini && root->data > left.maxi) ;
    
    if (currnode.isBST)
        ans = max(ans,currnode.size) ;
    
    return currnode ;
}



int largestBST(TreeNode<int>* root) 
{
    int ans = 0 ;
    info temp = solve(root,ans) ;
    
    return ans ;
    
}
