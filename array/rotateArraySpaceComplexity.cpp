#include<iostream>
#include<vector>
using namespace std;
int main(){
    //Input array and positions to shift / reverse
    vector<int> nums = {1,2,3} ;
    int k=7;

    int n = nums.size() ;

    k=k%n ; /* say size of the array n = 3 and k==3 then it is not worth time to rotate the array
                it will be the same array
                so we can define k as a function of n as k = an + x  where the a doesn't matter : 3,6,9 here
                for k=7 or k=6+1 we only have to shift interger 1 time cuz shifting 6 times will give the same array*/

    for (int i=0; i<k; i++) // adding padding of zero to move numbers
    {
        nums.push_back(0) ;
    }
    
    for (int i=n-1; i>=0; i--) // taking the elements to the end of the padding
    {
        nums[i+k] = nums[i] ;
    }
    
    /*
    int d = n+k-1 ;  // the element at the end(exceeding n-1) should join the array from back
    for (int i=k-1; i>=0; i--)  
    {
        nums[i]= nums[d] ; // say [1,2,3|4,5(crossed line)] -> [4,5|,1,2,2] to maintain the same sequence
        d++ ;  // put all the numbers from int end in same order from k-1
        nums.pop_back() ; // now that we have entered the element we can now delete them
    }
    */
   int d=n ;
   for (int i=0; i<k; i++)
   {
       nums[i]=nums[d] ;
       d++ ;
       nums.pop_back() ;
   }

   for (int i=0; i<nums.size() ; i++ ) cout<<nums[i]<<" " ;
    return 0 ;
}