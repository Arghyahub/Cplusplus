#include<iostream>
#include<vector>
using namespace std;
/*88. Merge Sorted Array
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/
int main(){
    int m = 3,  n=3 ;
    int mcheck = m ;
    vector<int> nums1 = {1,2,3,0,0,0} ;
    vector<int> nums2 = {2,5,6} ;

    int i=0, j=0 ;
    
    while (i<m+n)
    {
        if (nums2[j]<nums1[i] || nums1[i]==0)
        {
            // Shift all to elements upto the ith element
            for (int k=mcheck-1 ; k>=i; k--)
            {
                swap(nums1[k],nums1[k+1]) ;
            }
            mcheck ++ ;
            nums1[i]=nums2[j] ;
            j++ ;
            i++ ;
        }
        else
        {
            i++ ;
        }
    }

    for (int i=0; i<m+n; i++) {cout<<nums1[i]<<" " ;}
    

    return 0 ;
}