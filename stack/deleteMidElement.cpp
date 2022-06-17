// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    void delMid(int count, int size, stack<int>&s)
    {
        if (count==size)
        {
            s.pop() ;
            return ;
        }
        
        int temp =s.top() ;
        s.pop();
        
        delMid(count-1,size,s) ;
        
        s.push(temp) ;
        
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        if (sizeOfStack%2!=0)
            delMid( sizeOfStack-1 , sizeOfStack/2 , s) ;
        else
            delMid( sizeOfStack-1 , sizeOfStack/2 -1, s) ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends