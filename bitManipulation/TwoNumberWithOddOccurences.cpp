class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int x=0;
        for (int i=0; i<N; i++)
            x^=Arr[i] ;
        
        long long int rightMostBit = x&(-x) ; // only the bit which is different in both number
        // gives 1 when xor is done
        
        long long int res1=0 , res2=0;
        
        for (int i=0; i<N; i++){
            if (rightMostBit&Arr[i])
                res1^=Arr[i] ;
            else
                res2^=Arr[i] ;
        }
        
        vector<long long int> ans(2) ;
        if (res1>res2){
            ans[0]=res1;
            ans[1]=res2 ;
        }
        else{
            ans[1]=res1 ;
            ans[0]=res2 ;
        }
        
        return ans;
    }
};