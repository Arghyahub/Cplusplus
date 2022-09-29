class Solution {
    int las(vector<int>& nums,int diff, int prev, int index, int count )
    {
        if (index==nums.size()){
            return 0 ;
        }
        
        //include
        int inc=0 ;
        if (diff==INT_MAX || diff == nums[index] - prev ){
            int newdiff = (prev!=-1)? nums[index] - prev : INT_MAX ;
            inc = 1 + las(nums,newdiff,nums[index],index+1,count+1) ;
        }
        
        
        //exclude
        int exc = las(nums,diff,prev,index+1,count) ;
        return max(inc,exc) ;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<int> v ;
        
        return las(nums,INT_MAX,-1,0,0) ;
    }
};