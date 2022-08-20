//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        priority_queue<int,vector<int>,greater<int>> minheap ;
        
        for (int i=0; i<N; i++)
        {
            int temp = 0 ;
            for (int j=i; j<N; j++)
            {
                temp += Arr[j] ;
                
                if (minheap.size() < K)
                    minheap.push(temp) ;
                
                else if (temp > minheap.top())
                {
                    minheap.pop() ;
                    minheap.push(temp) ;
                }
            }
        }
        return minheap.top() ;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends