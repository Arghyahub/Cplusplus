class Solution {
    bool check(vector<int> &base, vector<int> &newbox)
    {
        if (newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2])
            return true;
        else
            return false;
    }
    
    int lengthOfLIS(vector<vector<int>>& nums) {
        int n = nums.size() ;
        vector<int> row1(n+1,0) ;
        
        for (int i=n-1; i>=0; i--){
            for (int iprev=i-1; iprev>=-1; iprev--){
                int inc=0;
                if (iprev==-1 || check(nums[i],nums[iprev]) )
                    inc = nums[i][2] + row1[i+1] ;
                
                int exc = row1[iprev+1] ;
                row1[iprev+1] = max(inc,exc) ;
            }
        }
        
        return row1[0] ;
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size() ;
        for (int i=0; i<n; i++)
            sort(cuboids[i].begin(),cuboids[i].end()) ;
        sort(cuboids.begin(),cuboids.end()) ;
        
        return lengthOfLIS(cuboids) ;
    }
};
