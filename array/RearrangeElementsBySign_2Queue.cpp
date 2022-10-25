class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        queue<int> pos;
        queue<int> neg;
        for (int i=0; i<n; i++){
            if (nums[i]<0) neg.push(nums[i]);
            else pos.push(nums[i]) ;
        }
        
        int i=0;
        while (!pos.empty() && !neg.empty()){
            nums[i++] = pos.front();
            pos.pop() ;
            nums[i++] = neg.front();
            neg.pop() ;
        }
        
        while (!pos.empty()){
            nums[i++] = pos.front();
            pos.pop() ;
        }
        
        while (!neg.empty()){
            nums[i++] = neg.front();
            neg.pop() ;
        }
        return nums;
    }
};