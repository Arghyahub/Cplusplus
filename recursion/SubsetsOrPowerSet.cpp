#include<iostream>
#include<string>
#include<vector>
using namespace std ;

void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans)
{
    if (index==nums.size())
    {
        ans.push_back(output) ;
        return ;
    }
    
    // Exclude 
    solve(nums,output,index+1,ans) ; // exclude the current element and move to the next element
    
    // Include
    output.push_back(nums[index]) ;  // include the current element and go for further combinations
    solve(nums,output,index+1,ans) ;
}
int main()
{
    vector<int> nums = {1,2,3}  ;
    vector<int> output ;
    vector<vector<int>> ans ;
    
    solve(nums,output,0,ans) ;
    
    for (int i=0; i<ans.size(); i++)
    {
        for (int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" " ;
        }
        cout<<endl ;
    }
        
}