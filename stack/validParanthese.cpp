bool isValidParenthesis(string expression)
{
    string s = "" ;
    for (char ch : expression)
    {
        s.push_back(ch) ;
        if (s.length()==1 && 
            (s[0]==')')|| (s[0]=='}') || (s[0]==']'))
            return false ;
        
        if (s.length()>=2 && 
           ( (s[s.length()-1]==')' && s[s.length()-2]=='(') ||
             (s[s.length()-1]=='}' && s[s.length()-2]=='{') ||
             (s[s.length()-1]==']' && s[s.length()-2]=='[') ) )
            {
                s.pop_back() ;
                s.pop_back() ;
            }
    }
            if (s.length()==0)
                return true ;
            else
                return false ;
}