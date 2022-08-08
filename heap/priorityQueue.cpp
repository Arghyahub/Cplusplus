#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    priority_queue<int> pq ;    // max priority Queue
    pq.push(50) ;
    pq.push(55) ;
    pq.push(53) ;
    pq.push(52) ;
    pq.push(54) ;

    cout<<"Priority queue : ";

    while(!pq.empty())
    {
        cout<<pq.top()<<" " ;
        pq.pop() ;
    } cout<<endl;



    // MIN heap
    priority_queue< int,vector<int>,greater<int> > minheap ;
    minheap.push(50) ;
    minheap.push(55) ;
    minheap.push(53) ;
    minheap.push(52) ;
    minheap.push(54) ;

    cout<<endl<<"Min heap : ";
    while(!minheap.empty())
    {
        cout<<minheap.top()<<" " ;
        minheap.pop() ;
    } cout<<endl;

    return 0 ;
}