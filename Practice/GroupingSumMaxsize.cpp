class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {     // RETURN THE MAXM SIZE OF GROUP WHERE SUM OF ANY TWO NUMBERS IS NOT DIVISIBLE BY K
        // SAY K=8
        vector<int> rem(K,0) ;      // STORE REMAINDERS WITH RESPECT TO K
        // BECUZ IF REM OF A PAIR ADD UPTO K , IT IS DIVISIBLE BY K
        for (int i=0; i<N; i++){
            int num=arr[i]%K;
            rem[num]++;
        }
        int ans=0;
        if (rem[0]) ans++;      // IF ANY NUMBER IS DIVISIBLE BY K, IT WILL BE ADDED TO THE LIST ONLY ONCE
        // OR ELSE, THE SUM OF THOSE TWO NUMBER WILL BE DIVISIBLE BY K
        
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
