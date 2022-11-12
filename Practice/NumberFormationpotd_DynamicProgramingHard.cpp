//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    // Q. Given three integers x, y, and z, the task is to find the sum of all the numbers formed by 
    // having 4 at most x times, having 5 at most y times, and having 6 at most z times as a digit.
  public:
    int getSum(int X, int Y, int Z) {
        long long sum[X+1][Y+1][Z+1] , nums[X+1][Y+1][Z+1] ;
        
        fill(&sum[0][0][0] , &sum[0][0][0] + ( (X+1)*(Y+1)*(Z+1) ) , 0 ) ;
        fill(&nums[0][0][0] , &nums[0][0][0] + ( (X+1)*(Y+1)*(Z+1) ) , 0 ) ;
        
        int m = 1e9+7 ;
        
        nums[0][0][0] = 1; // say we have 100 -> 0 + 4*(000) will give zero
        // so we should take 000 as 1 num
        long long ans = 0;
                    /**
                     * Say we want to get sum of all numbers with 1four 1five 1six
                     * (1,1,1) -> we can do it by having all the two digits numbers and push the third number at the end
                     * -------------------------------------------------------------------------------------------------
                     * Say we need to push 4 at the end 
                     * (1,1,1) ⬇️
                     *         (0,1,1) -> 56 , 65 only two numbers can be made
                     *         NOW ADD 4 TO THE END -> 56*10+4 , 65*10+4    => 564 , 654 = 1218
                     *         BUT WE CANNOT STORE 56 AND 65 SEPERATELY, THE SUM 56+64 = 121 WILL BE GIVEN
                     *         IN THE PREVIOUS STEP WE ADDED 4 TWO TIMES SO HERE WE HAVE TO DO THE SAME TO GET THE ANS
                     *         121*10 + 4(2) = 1218 [WHERE 2 IS THE NUMBER OF COMBINATION OF THE OTHER NUMBER]
                     * -------------------------------------------------------------------------------------------------
                     * Say we need to push 5 at the end 
                     * (1,1,1) ⬇️
                     *         (1,0,1) -> 46 , 64 only two numbers can be made
                     *         NOW ADD 5 TO THE END -> 46*10+5 , 64*10+5    => 465 , 645 = 1110
                     *         BUT WE CANNOT STORE 46 AND 64 SEPERATELY, THE SUM  46+64 = 110 WILL BE GIVEN
                     *         IN THE PREVIOUS STEP WE ADDED 5 TWO TIMES SO HERE WE HAVE TO DO THE SAME TO GET THE ANS
                     *         110*10 + 5(2) = 1110 [WHERE 2 IS THE NUMBER OF COMBINATION OF THE OTHER NUMBER]
                     * -------------------------------------------------------------------------------------------------
                     * Say we need to push 6 at the end 
                     * (1,1,1) ⬇️
                     *         (1,1,0) -> 45 , 54 only two numbers can be made
                     *         NOW ADD 6 TO THE END -> 45*10+6 , 54*10+6    => 456 , 546 = 1002
                     *         BUT WE CANNOT STORE 45 AND 54 SEPERATELY, THE SUM  45+54 = 99 WILL BE GIVEN
                     *         IN THE PREVIOUS STEP WE ADDED 6 TWO TIMES SO HERE WE HAVE TO DO THE SAME TO GET THE ANS
                     *         99*10 + 6(2) = 1002 [WHERE 2 IS THE NUMBER OF COMBINATION OF THE OTHER NUMBER]
                     * -------------------------------------------------------------------------------------------------
                     */
        for (int i=0; i<=X; i++){
            for (int j=0; j<=Y; j++){
                for (int k=0; k<=Z; k++){
                    
                    if (i>0){
                        sum[i][j][k] += (sum[i-1][j][k]*10 + 4*nums[i-1][j][k])%m ; //prev sum*10 + 4*(number of digits used)
                        // ** FOR FORMING 4 DIGIT NUMBER, WE NEED ALL KIND OF THREE DIGIT NUM
                        nums[i][j][k] += (nums[i-1][j][k])%m ;      // ** ADDING ALL THREE DIGIT NUMBER WITH 4 IN LAST PLACE
                    }
                    if (j>0){
                        sum[i][j][k] += (sum[i][j-1][k]*10 + 5*nums[i][j-1][k])%m ;
                        nums[i][j][k] += (nums[i][j-1][k])%m ;      // ** ADDING ALL THREE DIGIT NUMBER WITH 5 IN LAST PLACE
                    }
                    if (k>0){
                        sum[i][j][k] += (sum[i][j][k-1]*10 + 6*nums[i][j][k-1])%m ;
                        nums[i][j][k] += (nums[i][j][k-1])%m ;      // ** ADDING ALL THREE DIGIT NUMBER WITH 6 IN LAST PLACE
                    }
                    ans+=sum[i][j][k]%m ;
                }
            }
        }
        return ans%m ;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends