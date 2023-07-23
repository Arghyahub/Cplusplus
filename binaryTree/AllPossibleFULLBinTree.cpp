class Solution {
    vector<TreeNode*> solve(int n) {
        if (n==1)
            return {new TreeNode(0)} ;
        vector<TreeNode*> ans;
        for (int left=1; left<n; left+=2) {
            int right = n-1-left;

            vector<TreeNode*> leftComb = solve(left) ;
            vector<TreeNode*> rightComb = solve(right) ;

            for (auto l : leftComb) {
                for (auto r : rightComb) {
                    TreeNode* root = new TreeNode(0) ;
                    root->left = l;
                    root->right = r;
                    ans.push_back(root) ;
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!(n&1)) return {} ;
        return solve(n) ;
    }
};
