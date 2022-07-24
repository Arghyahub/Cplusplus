/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<climits>

int solve(TreeNode<int> *root , int &ans)
{
    if (root==NULL)
        return 0 ;
    int left = 0 , right = 0 ;
    
    left = solve(root->left,ans) ;
    right = solve(root->right,ans) ;
    
    int sum = root->data + left + right ;
    ans = max(ans,sum) ;
    
    return sum ;
}

int largestSubtreeSum(TreeNode<int> *root) {
    int ans = INT_MIN ;
    solve(root, ans) ;
    return ans ;
}
