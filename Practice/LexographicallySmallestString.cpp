//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
                                        //  FINDING IF ITS 2'S POWER
        int n = S.length() ;
        float f = log2(n) ;
        int m = f;
        float diff = f-m;
                                    // GIVEN IF ITS 2'S POWER THEN HALF K OR ELSE DOUBLE K

        if (diff>0) k*=2;
        else k=k/2 ;
        
        if (k>=n)                  // IF ALL THE NUMBERS ARE ALLOWED TO BE REMOVED , ie STRING IS EMPTY RETURN -1
            return "-1" ;
            
        if (k==0) return S ;        // IF NO ELEMENT IS TO BE REMOVED RETURN THE SAME STRING
            
        string ans = "" ;
        int tmp=0;
        
        for (int i=0; i<n; i++){
            while( !ans.empty() && tmp<k && ans[ans.length()-1]>S[i] ){ // PUSHING ELEMENTS AND IF ELEMENT IN ANS LAST IS GREATER, POP THAT
                ans.pop_back() ;
                tmp++;
            }
            ans.push_back(S[i]) ;
        }
        while(tmp<k){           // NOW IF YOU HAVEN'T POPPED K ELEMENTS THAN POP IT FROM THE BACK, IT WOULD STILL BE IN LEXALOGICAL ORDER
            ans.pop_back() ;
            tmp++ ;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends