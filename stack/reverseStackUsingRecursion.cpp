void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty()){
        stack.push(num) ;
        return ;
    }
    
    int temp = stack.top() ;
    stack.pop() ;
    
    insertAtBottom(stack,num) ;
    
    stack.push(temp) ;
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.empty())
        return ;
    
    int temp = stack.top() ;
    stack.pop() ;
    
    reverseStack(stack) ;
    
    insertAtBottom(stack,temp) ;
}