class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int l = 0 , r = n-1;
        int leftmax = arr[l] , rightmax = arr[r] ;
        long long ans = 0;
        
        while (l<r){ // arr[l] < arr[r] move forward
            if (arr[l]<arr[r]){
                l++;
                leftmax = max(leftmax,arr[l]) ;
                ans += leftmax - arr[l] ;
            }
            else{
                r--;
                rightmax = max(rightmax,arr[r]) ;
                ans += rightmax - arr[r] ;
            }
        }
        return ans;
    }
};

