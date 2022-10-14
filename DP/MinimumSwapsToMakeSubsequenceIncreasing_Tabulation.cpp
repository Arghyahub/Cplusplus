class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1) ;
        nums2.insert(nums2.begin(),-1) ;
        int N = nums1.size() ;
        vector<int> next(2,0) ;
        vector<int> curr(2,0) ;
        
        for (int i=N-1; i>=1; i--){
            for (int s=1; s>=0; s--){
                
                int prev1 = nums1[i-1] ;
                int prev2 = nums2[i-1] ;

                if (s)
                    swap(prev1,prev2) ;

                int ans = INT_MAX ;
                if (nums1[i]>prev1 && nums2[i]>prev2)
                    ans = next[0] ;
                if (nums1[i]>prev2 && nums2[i]>prev1)
                    ans = min(ans , 1 + next[1] ) ;

                curr[s] = ans ;
            }
            next=curr ;
        }
        return curr[0] ;
    }
};
