//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class trie
// {
//     public:
//     char c;
//     unordered_map<char,bool> mp;
// };

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        unordered_map<string,int> mp ;

        for (int i=0; i<N; i++){    // take all string
            string str = li[i] ;
            string tmp="" ;
            for (auto ch : str){    // create all continous substrings
                tmp.push_back(ch) ;
                mp[tmp]++ ;         // enter that into map
            }
        }
        
        vector<int> ans(Q) ;
        int i=0;
        
        for (int j=0; j<Q; j++){        // check the query's value
            string str = query[j] ;
            ans[i++] = mp[str] ;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends