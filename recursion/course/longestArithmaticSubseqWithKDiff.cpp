class Solution {
    int getAns(vector<int>& arr, int diff,int prev, int i)
    {
        if (i==arr.size()){
            return 0 ;
        }
        
        int inc=0 , exc ;
        
        if (prev==INT_MIN || (arr[i]-prev) == diff){
            inc = 1 + getAns(arr,diff,arr[i],i+1) ;
        }
        
        exc = getAns(arr,diff,prev,i+1) ;
        
        return max(inc,exc) ;
    }
    
    
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        return getAns(arr,difference,INT_MIN,0) ;
    }
};