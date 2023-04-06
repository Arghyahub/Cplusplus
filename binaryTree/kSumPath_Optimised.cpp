class Solution{
    void solve(Node *root, int &k, int &total, int &ans, unordered_map<int,int> &path){
        if (!root)
            return ;
        
        total+=root->data ;		// Add sum to path
        ans+= path[total-k] ;
        path[total] ++;		// Add the sum to the path
        
        solve(root->left,k,total,ans,path) ;	// Go to the nodes with the path and the sum
        solve(root->right,k,total,ans,path) ;
        
        path[total] --;		// As we are moving back, erase the path
        total-=root->data ;	// remove the sum as we are moving back and might change branch
        
    }
  public:
    int sumK(Node *root,int k)
    {
        unordered_map<int,int> path;
        path[0] = 1;
        int total=0 , ans=0;
        solve(root,k,total,ans,path) ;
        return ans;
    }
};
