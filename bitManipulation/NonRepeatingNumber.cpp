class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int x = 0;
        for (auto it : nums)
            x = x^it;
        
        int rmbit=0;
        for (int i=0; i<32; i++)	// Find the right most bit
            if ((x>>i)&1){
                rmbit = i;
                break;
            }
        
        int ans = 0;
        for (int it : nums){
            if ((it>>rmbit) & 1 ) {  // Only xor set of those numbers whose rightmost bit is set
                ans = ans^it;
            }
        }
        int ans2 = ans^x;
        if (ans>ans2)
            swap(ans,ans2) ;
        return {ans,ans2};
    }
};
