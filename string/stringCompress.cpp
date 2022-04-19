#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    vector<char> chars ;
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        char x;
        cin>>x ;
        chars.push_back(x) ;
    }
    int ansindex=0;
    int i=0 ;
    while(i<n)
    {
        int j=i+1 ;
        chars[ansindex++]=chars[i] ;
        while (j<n && chars[i]==chars[j])
            j++ ;
        
        int diff = j-i ;
        if (diff>1)
        {
            string s = to_string(diff) ;
            for (char ch : s)
            {
                chars[ansindex++] = ch ;
            }
        }
        
        i=j ;
    }
    while (chars.size()>ansindex)
        chars.pop_back() ;

    for (int i=0; i<chars.size(); i++)
        cout<<chars[i]<<" " ;
    cout<<endl<<ansindex ;
}