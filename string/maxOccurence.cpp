#include<iostream>
#include<string>
using namespace std;

void maxOccurenceCh(string str)
{
    // Now we wil use hashing , the range of letters from 'a' to 'z' is 26
    int letter[26] = {0} ;

    for (int i=0; i<str.length() ; i++)
    {
        int ch = str[i] - 'a' ;
        letter[ch]+=1 ;
    }

    int maxcount =-1, ans = 0 ;
    for (int i=0; i<26; i++)
    {
        if (letter[i]>maxcount) // agar letter array ki ascii-'a' position par count max ho
        {
            maxcount=letter[i] ; // toh wo hua max count
            ans = i ;            // aur max count ki asci-'a' value hogi highest occuring
        }
    }

    char x = ans + 'a' ;
    cout<<x<<endl ;

}
int main(){
    string str ; 
    cin>>str ;  // suppose all the letters are lowercase
    maxOccurenceCh(str) ;

    return 0 ;
}