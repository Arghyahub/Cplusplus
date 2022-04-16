#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>&nums,int low, int high)
    {
        while (low<high)
            swap(nums[low++],nums[high--] );
    }
int main(){
    // so given [1,2,3,|4,5] given n=5 k=2 convert to [4,5|1,2,3]
    // rotate the entire array = [5,4,3,2,1] wait a minute
    // break the array in two parts  -> [5,4|,3,2,1]
    // now rotate the two halves (0,k-1),(k,n-1) -> [4,5|,1,2,3] 

    vector<int> nums = {1,2,3,4,5} ;
    int n= nums.size() ,k=2;
    k=k%n ;
    rotate(nums,0,n-1) ;
    rotate(nums,0,k-1) ;
    rotate(nums,k,n-1) ;

    for (int i=0; i<n; i++) { cout<<nums[i]<<" " ; }

    return 0 ;
}