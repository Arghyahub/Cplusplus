
// } Driver Code Ends
class Solution {
    
    void bfs(long long X, int num,long long &ans)
    {
        queue<long long> q;
        q.push(num) ;
        
        while (!q.empty()){
            long long front = q.front() ;
            q.pop() ;
            
            if (front > X) break;
            ans=max(ans,front) ;
            
            int cond = front%10 ;
            
            if (cond==0)
                q.push(front*10+1) ;
            else if (cond==9)
                q.push(front*10+8) ;
            else{
                q.push(front*10+cond-1) ;
                q.push(front*10+cond+1) ;
            }
        }
    }
    
    
  public:
    long long jumpingNums(long long X) {
        long long ans=0;
        for (int i=1; i<10 && i<=X; i++)
            bfs(X,i,ans) ;
            
        return ans;
    }
};