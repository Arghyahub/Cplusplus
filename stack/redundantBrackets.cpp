#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st ;
    for (char ch : s)
    {
        if ( ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' )
        {
            st.push(ch) ;
        }
        else if ( ch==')' )
        {
            bool ans = true ;
            while(  st.top()!='(' )
            {
                if (st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/')
                    ans = false ;
                st.pop() ;
            }
            st.pop() ;
            
            if (ans)
                return true ;
        }
    }
    return false ;
}
