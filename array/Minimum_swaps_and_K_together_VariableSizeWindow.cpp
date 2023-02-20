class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int num=0;
        for (int i=0; i<n; i++)
            if (arr[i]<=k)
                num++;
        if (num==0) return 0;
        
        int ans=num, exist=0;
        int l=0, r=0;
        while (r<num){
            if (arr[r]<=k)
                exist++;
            r++;
        }
        if (exist==num) return 0;
        ans = min(ans,num-exist) ;
        
        for (; r<n; r++){
            if (arr[l]<=k) exist--;
            l++;
            if (arr[r]<=k) exist++;
            ans = min(ans,num-exist) ;
        }
        
        return ans;
    }
};
