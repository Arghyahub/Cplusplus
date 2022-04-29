#include<iostream>
using namespace std;

class node
{
    public:
    int data ; // where the data is stored

    node* next ; // a pointer poiting towards next node

};
int main(){
    
    node* node1 = new node() ;  // node 1 ( a pointer of datatype node) having a heap Node

    cout<<node1->data<<endl ;
    cout<<node1->next<<endl ;

    return 0 ;
}