class Solution {
    int getans(vector<int>& cost, int s,int n)
    {
        if (s==n)
            return 0 ;
        
        if (s > n)
            return -1 ;
        
        int ones = getans(cost,s+1,n) ;
        int twos = getans(cost,s+2,n) ;
        int c = (s>=0)? cost[s]:0 ;
        
        
        if (ones!=-1 && twos==-1) return ones + c ;
        if (ones==-1 && twos!=-1) return twos + c ;
        
        return min(ones,twos) + c ;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return getans(cost,-1,cost.size()) ;
    }
};