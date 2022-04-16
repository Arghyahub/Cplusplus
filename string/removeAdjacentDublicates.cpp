#include<iostream>
#include<string>
using namespace std;
int main(){
    // ::  Approach  1 ::
    string s = "abbaca" ; // ans should be ca
    string ans = "" ;

    for (int i=0; i<s.length(); i++)
    {
        int n=ans.length() ; // agar ans khali ho toh kahe ka checking? direct character dalo
        if (n!=0 && ans[n-1]==s[i]) // agar last added character same ho toh delete kardo
            ans.pop_back() ;        // Last index wala jhamela khattam
        else
            ans.push_back(s[i]) ;
    }
    cout<<"\n:: Approach1 :: "<<ans<<endl ;

    //  ::  Approach 2  ::
    s = "abbaca" ;
    ans = "" ;

    for (char ch : s)
    {
        ans.push_back(ch) ; // pehle character add kardo
        int n = ans.length() ;
        if (n>=2 && ans[n-2]==ans[n-1])  // 2 size ki window mai check karo, kyuki tab hi tum 2 element hata paoge
        {                               // agar last aur 2nd last element same ho toh dono ura do
            ans.pop_back() ;            // warna size kamm ho toh next element add kardo taki check kar pao
            ans.pop_back() ;
        }
    }
    cout<<"\n:: Approach2 :: "<<ans<<endl ;

    return 0 ;
}