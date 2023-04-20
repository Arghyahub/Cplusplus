// https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/3437397/tle-and-int-overflow-to-finally-accepted-images-added/
#define ll long long
class Solution {
    unordered_map<ll,pair<ll,ll>> levelIndex;
    ll ans = 0;

    void solve(TreeNode* root, ll index, ll level){
        if (!root) return;
        if (levelIndex[level].first==0)
            levelIndex[level].first = index;
        levelIndex[level].second = max( levelIndex[level].first , index ) ;

        ans = max(ans , levelIndex[level].second - levelIndex[level].first) ;

        index -= levelIndex[level].first + 1 ;
        
        level++;
        solve(root->left,2*index-1,level) ;
        solve(root->right,2*index,level) ;
    }

public:
    int widthOfBinaryTree(TreeNode* root) {
        solve(root,1,1) ;
        return ans+1;
    }
};
