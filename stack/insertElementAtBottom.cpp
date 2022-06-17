void insertAtBottom(stack<int>& myStack, int x)
{
    if (myStack.empty()){
        myStack.push(x) ;
        return ;
    }
    
    int temp = myStack.top() ;
    myStack.pop() ;
    
    insertAtBottom(myStack,x) ;
    
    myStack.push(temp) ;
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    insertAtBottom(myStack,x ) ;
    return myStack ;
}