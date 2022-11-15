#include<iostream>
#include<vector>
using namespace std;

// [1,2,3] , [1,3,2] , [2,1,3] , [2,3,1] , [3,2,1] , [3,1,2] , 

void solve(vector<int> nums,vector<vector<int>> &ans, int index)
{
    if (index>=nums.size())
    {
        ans.push_back(nums) ;
        return ;
    }
    
    // run a for loop and swap every element with the next
    for (int i=index; i<nums.size(); i++)
    {
        swap(nums[i],nums[index]) ;
        solve(nums,ans,index+1) ;
        
        // back tracking
        swap(nums[i],nums[index]) ;
    }
}

int main()
{
    vector<int> nums = {1,2,3} ;
    vector<vector<int>> ans ;
    solve(nums,ans,0) ;
    // return ans ;
    for (int i=0; i<ans.size(); i++)
    {
        cout<<"[" ;
        for (int j=0; j<ans[0].size(); j++)
            cout<<ans[i][j]<<"," ;
        cout<<"] , " ;
    }
    return 0 ;
}