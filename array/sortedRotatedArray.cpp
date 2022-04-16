#include<iostream>
#include<vector>
using namespace std;
/*Input: nums = [3,4,5,1,2]
Output: true

Input: nums = [2,1,3,4] -> 2 > 1
Output: false.*/
int main(){
    /* If we go circular
    Case 1 : Sorted Array : [1,2,3,4,5] here 1 is smaller than 5 (next element in roatation) .:. ~~~ 1 time
    Case 2 : Sorted&Rotated : [4,5,1,2,3] here 1 is smallet than 5 (next element in rotation) .:. ~~~ 1 time
    Case 3 : Breaker : [1,3,5,4,7,2] 5>4 && 7>2 && 2>1 .:. ~~ more than 1 time 
    Case 4 : all same number [1,1,1,1] here there's no big or small .:. 0 times
    */

   vector<int> arr = {3,4,5,1,2} ;

   int counter=0 , n=arr.size() ;
   for (int i=1; i<=n; i++)
   {
       if (arr[i-1]>arr[i%n])
        counter++ ;
   }

//    if (arr[arr.size()-1]>arr[0]) {counter++ ;}
    cout<< (counter<=1)?"True":"False" ;
    return 0 ;
}