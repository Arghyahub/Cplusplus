// next permutation means it would be a greater number, to build just a greater number you need to swap with the just bigger integer, if done then sort the rest left half and thats the ans
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1) return ;
        int n = nums.size() ;
        
        for (int i=n-2; i>=0; i--){
            pair<int,int> p = {INT_MAX,i} ;
            for (int j=i+1; j<n; j++){
                if (nums[j]>nums[i] && nums[j]<p.first){
                    p.first=nums[j] , p.second=j;
                }
            }
            swap(nums[p.second],nums[i]) ;
            if (p.second!=i){
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        
        sort(nums.begin(),nums.end()) ;
    }
};
