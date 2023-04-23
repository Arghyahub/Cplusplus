class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int l = 0 , N = nums.size() ;
        vector<int> frq(51,0) ;
        vector<int> ans;

        for (int r=0; r<N; r++){
            int norm = (nums[r]<=0)? -nums[r] : -1;
            if (norm!=-1)
                frq[norm]++;
            if (r>=k){
                norm = (nums[l]<=0)? -nums[l] : -1;
                if (norm!=-1)
                    frq[norm]--;
                l++;
            }

            if (r>=k-1) {
                int count = 0 , mini=0;
                for (int i=50; i>=0; i--){
                    count+=frq[i] ;
                    if (count>=x){
                        mini = i;
                        break;
                    }
                }
                ans.push_back(-mini) ;
            }
        }
        return ans;
    }
};
