#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool possibe(int x, int y,vector<vector<int>> m, int n,vector<vector<bool>> visited)
{
    if ( (x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0 )
    {
        return true ;
    }
    else
        return false ;
}
void solve(vector<vector<int>> &m,int n, vector<vector<bool>> visited, string store, vector<string> &ans, int x, int y)
{
    if (x==n-1 && y==n-1) // if last index is reached then game ends , store values in ans
    {
        ans.push_back(store) ;
        return ;
    }
    
    visited[x][y]=1 ; // put visited =1 for the blocks you have already visited to avoid duplicate paths
    
    // Go Down
    int newx=x+1 ;
    int newy=y ;
    if (possibe(newx,newy,m,n,visited))
    {
        store.push_back('D') ; // Enter the answer into the string
        solve(m,n,visited,store,ans,newx,newy) ; // the rest will be ha,dled by the function
        store.pop_back() ;  // remove the answer for further movement
    }
    
    // Go LEFT
    newx=x ;
    newy=y-1 ;
    if (possibe(newx,newy,m,n,visited))
    {
        store.push_back('L') ;
        solve(m,n,visited,store,ans,newx,newy) ;
        store.pop_back() ;
    }
    
    // Go Right
    newx=x ;
    newy=y+1 ;
    if (possibe(newx,newy,m,n,visited))
    {
        store.push_back('R') ;
        solve(m,n,visited,store,ans,newx,newy) ;
        store.pop_back() ;
    }
    
    // Go Up
    newx=x-1 ;
    newy=y ;
    if (possibe(newx,newy,m,n,visited))
    {
        store.push_back('U') ;
        solve(m,n,visited,store,ans,newx,newy) ;
        store.pop_back() ;
    }
    
    visited[x][y]=0 ;  // check given image
}

int main() 
{
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
        } ;
    int n=4 ;// size
    
    vector<string> ans ;
    if (m[0][0]==0) // if the first block is 0 then the mouse cannot move, game ends
        return 0 ;
        // return ans ;
    vector<vector<bool>> visited(n,vector<bool>(n)) ;  // Define a visited array so that, when ever you visit a block turn it to 1
    string store="" ;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            visited[i][j]=0 ;
    
    solve(m,n,visited,store,ans,0,0) ;
    
    sort(ans.begin(),ans.end()) ;
    
    // return ans;

    for (int i=0; i<ans.size(); i++)
    {
        for (int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j] ;
        cout<<endl ;
    }
}