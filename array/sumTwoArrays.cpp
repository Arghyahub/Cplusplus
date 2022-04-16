#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &arr)
{
    int start=0,end=arr.size()-1 ;
    while (start<end)
        swap(arr[start++],arr[end--]) ;
}

int main(){
    /*arr1 & arr2
    Case1: arr1> arr2 or arr1<arr2 -> add take the carry and just keep adding the carry to left over array
    Case2: suppose[9,9,9]+[9,9,9] = [1,9,9,8] we have to shift numbers once and then add the carry to 1st place
    */
    vector<int> arr = {1,2,3,4};
    vector<int> brr = {6} ;
    vector<int> ans = {} ;
    int n=arr.size() , m=brr.size() ;

    int i=n-1 , j=m-1 ;
    int carry=0 , val=0;

    while (i>=0 && j>=0)
    {
        val = arr[i] + brr[j] + carry ;
        carry=val/10 ;
        ans.push_back(val%10) ;
        i--;
        j-- ;
    }
    // solving choti bari problem of array Case1

    while (j>=0)
    {
        val = brr[j] + carry ;
        carry=val/10 ;
        ans.push_back(val%10) ;
        j-- ;
    }
    while (i>=0)
    {
        val = arr[i] + carry ;
        carry=val/10 ;
        ans.push_back(val%10) ;
        i-- ;
    }
    if (carry!=0)
        ans.push_back(carry) ;

    reverse(ans) ;

    for (int i=0; i<ans.size(); i++) { cout<<ans[i]<<" " ; }

    return 0 ;
}