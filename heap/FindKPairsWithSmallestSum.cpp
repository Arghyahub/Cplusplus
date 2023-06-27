class Comp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) {
        return (a[0]+a[1]) > (b[0]+b[1]) ;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Comp> minh;
        vector<vector<int>> ans;

        for (int i=0; i<nums1.size() && i<k; i++)
            minh.push({nums1[i],nums2[0],0}) ;

        while (!minh.empty() && ans.size()<k){
            auto vec = minh.top() ; minh.pop() ;
            ans.push_back({vec[0],vec[1]}) ;
            if (vec[2]!=nums2.size()-1){
                minh.push({vec[0], nums2[vec[2]+1] , vec[2]+1 }) ;
            }
        }

        return ans;
    }
};
