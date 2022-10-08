//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int check(int *alp)     // GIVES THE NUMBER OF DISTINCT ELEMENTS
    {
        int count = 0;
        for (int i=0; i<26; i++)
            if (alp[i] > 0)
                count++;
        return count ;
    }
    
  public:
    int countOfSubstrings(string S, int K) {    // SOLVE USING SLIDING WINDOW
        if (K>S.length()) return 0 ;
        if (K==1) return 0 ;
        
        int alp[26] , ans=0 ;
        for (int i=0; i<26; i++) alp[i] = 0;    
        
        string str = "" ;
        for (int i=0; i<K ; i++){   // ADD ELEMENTS IN K SIZED WINDOW
            str+= S[i] ;
            alp[ S[i] - 'a' ]++ ;   // INCREMENT THE NUMBER OF OCCURENCE
        }
        
        int dist = check(alp) ;// GET NUMBER OF DISTINCT ELEMENTS AND CHECK CONDITION
        if (dist==K-1) 
            ans++ ;
        
        for(int i=K; i<S.size(); i++)
        {
            char old = str[0] ;     // TAKE THE LAST CHARACTER
            str.erase(0,1) ;    // ERASE IT
            
            char nw = S[i] ;    // TAKE THE NEW CHARACTER
            str+=nw ;           // ADD IT TO THE STRING
            
            alp[old-'a']--;     // DECREMENT THE OCCURENCE OF OLD CHARACTER
            alp[nw - 'a']++ ;  // DECREMENT THE OCCURENCE OF NEW CHARACTER
            
            int dist = check(alp) ; // CHECK CONDITION
            if (dist==K-1) 
                ans++ ;
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
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends