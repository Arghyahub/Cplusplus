int findMinimumCost(string str) {
  // Write your code here
    string s ;
    for (char ch : str)
    {
        s.push_back(ch) ;
        if (s.size()>=2 && s[s.size()-2]=='{' && s[s.size()-1]=='}' )
        {
            s.pop_back() ;
            s.pop_back() ;
        }
    }
    if (str.length()==0)
        return 0 ;
    else if (str.length()%2!=0)
        return -1 ;
    
    int count = 0 ;
    for (int i=0; i<s.size(); i++)
    {
        char ch1 = s[i] ;
        char ch2 = s[i+1] ;
        if ( (ch1=='{' && ch2=='{') || (ch1=='}' && ch2=='}' ) )
            count++ ;
        else if ( ch1=='}' && ch2=='{' )
            count+=2 ;
        
        if (i<s.size())
            i++ ;
    }
    return count ;
    
}