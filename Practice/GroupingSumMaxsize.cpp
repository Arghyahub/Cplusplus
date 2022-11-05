class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        vector<int> rem(K,0) ;
        for (int i=0; i<N; i++){
            int num=arr[i]%K;
            rem[num]++;
        }
        int ans=0;
        if (rem[0]) ans++;
        
        for (int i=1; i<=K/2; i++){
            if (i != K-i){
                ans+=max(rem[i],rem[K-i]) ;
            }
            else{               // say num=4, then adding two 4's will give 8, so add only 1
                if (rem[i]!=0)
                    ans++ ;
            }
        }
        return ans;
    }
};
