class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums[0], cnt=1;
        for (int i=1; i<nums.size(); i++){
            if (cnt==0){
                n = nums[i];
                cnt=1;
            }
            else if (nums[i]==n)
                cnt++;
            else
                cnt--;
        }

        cnt=0;
        for (auto num : nums)
            if (num==n)
                cnt++;

        return (cnt>nums.size()/2)? n:-1;
    }
};
