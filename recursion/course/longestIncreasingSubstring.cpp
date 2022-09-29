class Solution {
    int max(int a , int b){
        if (a>b)
            return a ;
        else
            return b ;
    }
    
    void getSubs(vector<int>& nums, int &ans, vector<int> &v, int i)
    {
        if (i==nums.size()){
            ans = max(ans,v.size()) ;
            return ;
        }
        
        // include if greater
        bool check = false;
        if (v.size() == 0){
            v.push_back(nums[i]) ;
            check=true;
        }
        else{
            if (nums[i] > v[v.size()-1]){
                v.push_back(nums[i]) ;
                check = true ;
            }
        }
        getSubs(nums,ans,v,i+1) ;   
        
        
        // exlude
        if (check) v.pop_back() ;
        getSubs(nums,ans,v,i+1) ;
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0 ;
        vector<int> v ;
        getSubs(nums,ans, v ,0) ;
        return ans ;
    }
};