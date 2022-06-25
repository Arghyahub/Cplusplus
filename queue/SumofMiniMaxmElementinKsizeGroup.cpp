#include<iostream>
#include<queue>
using namespace std ;

int main()
{
    queue<int> smallq;
    queue<int> largeq;
    int mini = 0 ;
    int maxi = 0 ;
    int ans = 0 ;
    int arr[]={2, 5, -1, 7, -3, -1, -2} ;
    int k=4 , n=sizeof(arr)/sizeof(int) ;

    

    for (int i=0; i<k; i++)
    {
        mini = arr[i] <= arr[mini]? i:mini ;
        maxi = arr[i] >= arr[mini]? i:maxi ;
    }
    smallq.push(mini) ;
    largeq.push(maxi) ;

    for (int i=k-1; i<n; i++)
    {
        while ( (!smallq.empty() && smallq.front() <= i-k) || ( !smallq.empty() && arr[smallq.front()] > arr[i] ) )
            smallq.pop() ;
        if (smallq.empty()){
            mini = i ;
            smallq.push(i) ;
        }
        else 
            mini = smallq.front() ;


        while ( (!largeq.empty() && largeq.front() <= i-k) || ( !largeq.empty() && arr[largeq.front()] < arr[i] ) )
            largeq.pop() ;
        if (largeq.empty()){
            maxi = i ;
            largeq.push(i) ;
        }
        else 
            maxi = largeq.front() ;

        cout<<"Max : "<<arr[maxi]<<endl;
        cout<<"Mini : "<<arr[mini]<<endl;
        ans+=arr[maxi]+arr[mini] ;
        cout<<"Diff : "<<arr[maxi]+arr[mini]<<"\n\n" ;
    }

    cout<<"\nAnswer :"<<ans<<endl;
    return 0 ;
}
