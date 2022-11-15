#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // Q. FIND THE LONGEST SUBARRAY WHOSE DIFF OF LARGEST AND GREATEST ELEMENT IS <=1

        // code here
        multiset<int> s;
        
        int l=0, ans=0;
        
        for (int i=0; i<N; i++){
            s.insert(arr[i]) ;
            // cout<<arr[i]<<endl;
            while (l<i && !s.empty() && ( *(s.rbegin()) - *(s.begin()) > 1 ) ){
                // cout<<arr[l]<<" " ;
                s.erase(arr[l]) ;
                l++;
            }
            // cout<<endl;
            int sz = s.size() ;
            ans=max(ans,sz) ;
        }
        
        return ans ;
    }
};