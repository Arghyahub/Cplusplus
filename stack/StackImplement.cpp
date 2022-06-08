#include<iostream>
using namespace std;

class Stack
{
    public:
    int* arr ;
    int size ;
    int top ;
    
    Stack(int size)
    {
        this->size= size ;
        this->arr= new int[size] ;
        top = -1 ;
    }

    void push(int element)
    {
        if (size-top > 1)
        {
            top++ ;
            arr[top]=element ;
        }
        else
        {
            cout<<"Stack Overflow\n" ;
        }
    }

    void pop()
    {
        if (top>=0)
        {
            top-- ;
        }
        else
            cout<<"No Element Present\n" ;
    }

    void peek()
    {
        if (top<0)
            cout<<"No Element Present\n" ;
        else
            cout<<"\nTop -> "<<arr[top] ;
    }

    void isEmpty()
    {
        if (top<0)
            cout<<"Stack is Empty\n" ;
    }

    void print()
    {
        cout<<"\nStack : " ;
        for (int i=0; i<=top; i++)
            cout<<arr[i]<<" " ;
    }

};



int main(){
    
    Stack s(5) ;

    s.push(10) ;
    s.push(20) ;
    s.push(30) ;
    s.print() ;

    s.pop() ;
    s.print() ;

    s.peek() ;

    s.print() ;

    

    return 0 ;
}