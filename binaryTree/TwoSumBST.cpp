// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
void inorderTraverse(BinaryTreeNode<int>* root, vector<int> &ans)
{
    if (root==NULL)
        return ;
    
    inorderTraverse(root->left,ans) ;
    ans.push_back(root->data) ;
    inorderTraverse(root->right,ans) ;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> ans ;
    inorderTraverse(root,ans) ;
    
    for (int i=0, j=ans.size()-1 ; i<j; )
    {
        if (ans[i]+ans[j]==target)
            return true ;
        else if (ans[i]+ans[j] > target)
            j-- ;
        else
            i++ ;
    }
    return false ;
  
}